#include <algorithm>
#include <vector>
#include <set>
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <math.h>
#include <mutex>

// #define DEBUG_COMPARE true

void printvec(const std::vector<int> &my_vector);
std::vector<int> greedy(const int number, const std::vector<int> &launch_domain);
void generate_prime_factor(int big_number, std::vector<int> &factors_result);
std::vector<float> divide(const std::vector<int> &a, const std::vector<int> &b);
void generate_prime_factorization(const int number, std::unordered_map<int, int> &result, std::vector<int> &unique_prime);
void enumerate_placement(const int prime, int power, int num_places,
                         std::vector<int> partial_result, std::vector<std::vector<int>> &final_result);
void cartesian_product(std::vector<int> unique_prime,
                       const std::unordered_map<int, std::vector<std::vector<int>>> &prime_placement,
                       const std::vector<int> &partial_result,
                       std::vector<std::vector<int>> &final_result);
std::vector<int> precise_enumerate(int number, const std::vector<int> &launch_domain);
void printvec(const std::vector<float> &my_vector);
float judge(std::vector<std::vector<int>> candidates, std::vector<int> launch_space, int node_num, int dx, int dy);
std::string myvec2str(const std::vector<int> &my_vector);
void printvec(const std::vector<int> &my_vector);
std::string myvec2str(const std::vector<float> &my_vector);
void printvec(const std::vector<float> &my_vector);
unsigned int C(int n, int k);

// Helper function: factorize a number (big_number) into sorted prime factors (factors_result)
void generate_prime_factor(int big_number, std::vector<int> &factors_result)
{
  auto generate_factors = [&](int factor)
  {
    while (big_number % factor == 0)
    {
      factors_result.push_back(factor);
      big_number /= factor;
    }
  };
  // Fundamental theorem of arithmetic time!
  const unsigned num_primes = 62;
  const int primes[num_primes] = {2, 3, 5, 7, 11, 13, 17, 19,
                                  23, 29, 31, 37, 41, 43, 47, 53,
                                  59, 61, 67, 71, 73, 79, 83, 89,
                                  97, 101, 103, 107, 109, 113, 127, 131,
                                  137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                                  211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293
                                  };
  // Increase the size of the prime number table if you ever hit this
  assert(big_number <= (primes[num_primes - 1] * primes[num_primes - 1]));
  for (size_t i = 0; i < num_primes; i++)
  {
    if (primes[i] * primes[i] > big_number) // There is at most 1 prime whose index >= i
      break;
    generate_factors(primes[i]);
    if (big_number == 1)
      break;
  }
  if (big_number > 1) // E.g., we need to put 137 into the result for 2 * 137
    factors_result.push_back(big_number);
}


// DefaultMapper's algorithm
std::vector<int> greedy(const int number, const std::vector<int> &launch_domain)
{
  int dim = launch_domain.size();
  std::vector<int> result;
  result.resize(dim, 1);
  if (number == 1)
  {
    return result;
  }
  // factorize number into prime_nums (sorted from smallest to largest)
  std::vector<int> prime_nums;
  generate_prime_factor(number, prime_nums);
  // Assign prime nums onto the dimensions
  // from the largest primes down to the smallest, in a greedy approach
  std::vector<double> domain_vec;
  for (auto i = 0; i < dim; i++)
    domain_vec.push_back((double)launch_domain[i]); // integer to double

  // from the largest primes down to the smallest
  for (int idx = prime_nums.size() - 1; idx >= 0; idx--)
  {
    // Find the dimension with the biggest domain_vec
    int next_dim = std::max_element(domain_vec.begin(), domain_vec.end()) - domain_vec.begin();
    int next_prime = prime_nums[idx];
    result[next_dim] *= next_prime;
    domain_vec[next_dim] /= next_prime;
  }
  return result;
}


// Chapel's algorithm: https://github.com/chapel-lang/chapel/blob/1dd8dcaa17/modules/dists/DSIUtil.chpl#L184
std::vector<int> chapel_greedy(const int number, const std::vector<int> &launch_domain)
{
  int dim = launch_domain.size();
  std::vector<int> result;
  result.resize(dim, 1);
  if (number == 1)
  {
    return result;
  }
  // factorize number into prime_nums (sorted from smallest to largest)
  std::vector<int> prime_nums;
  generate_prime_factor(number, prime_nums);
  // Assign prime nums onto the dimensions
  // from the smallest primes up to the largest, in a greedy approach

  // from the smallest primes up to the largest
  for (int idx = 0; idx < prime_nums.size(); idx++)
  {
    // Find the dimension with the smallest number
    int next_dim = std::min_element(result.begin(), result.end()) - result.begin();
    int next_prime = prime_nums[idx];
    result[next_dim] *= next_prime;
  }
  std::sort(result.begin(), result.end(), std::greater<int>());
  return result;
}

// Helper function: divide a / b elementwise, return float
std::vector<float> divide(const std::vector<int> &a, const std::vector<int> &b)
{
  assert(a.size() == b.size());
  std::vector<float> result;
  for (size_t i = 0; i < a.size(); i++)
  {
    result.push_back((float)a[i] * 1.0 / (float)b[i]);
  }
  return result;
}

// quick pow for int
inline int binpow(int a, int b)
{
  int res = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

void generate_prime_factorization(const int number, std::unordered_map<int, int> &result, std::vector<int> &unique_prime)
{
  std::vector<int> prime_nums;
  generate_prime_factor(number, prime_nums);

  std::set<int> prime_num_set(prime_nums.begin(), prime_nums.end());
  unique_prime = std::vector<int>(prime_num_set.begin(), prime_num_set.end());

  std::multiset<int> prime_num_multiset(prime_nums.begin(), prime_nums.end());
  size_t total_elements = 0;
  for (size_t i = 0; i < prime_nums.size(); i++)
  {
    if (result.count(prime_nums[i]) == 0)
    {
      size_t appear_times = prime_num_multiset.count(prime_nums[i]);
      total_elements += appear_times;
      result.insert({prime_nums[i], appear_times});
    }
  }
  assert(total_elements == prime_nums.size());
}

// result contain all possible ways of placement to decompose {prime}^{power} into {num_places}
void enumerate_placement(const int prime, int power, int num_places,
                         std::vector<int> partial_result, std::vector<std::vector<int>> &final_result)
{
  if (power < 0)
  {
    assert(false);
  }
  if (num_places == 1)
  {
    int last_element = binpow(prime, power);
    partial_result.push_back(last_element);
    final_result.push_back(partial_result);
    return;
  }
  int cur_element = 1;
  for (int i = 0; i <= power; i++)
  {
    partial_result.push_back(cur_element);
    enumerate_placement(prime, power - i, num_places - 1, partial_result, final_result);
    partial_result.pop_back();
    cur_element *= prime; // cur_element = {prime}^{i}
  }
}

void cartesian_product(std::vector<int> unique_prime,
                       const std::unordered_map<int, std::vector<std::vector<int>>> &prime_placement,
                       const std::vector<int> &partial_result,
                       std::vector<std::vector<int>> &final_result)
{
  if (unique_prime.size() == 0)
  {
    final_result.push_back(partial_result);
    return;
  }
  int prime = unique_prime[unique_prime.size() - 1];
  std::vector<std::vector<int>> all_placement = prime_placement.at(prime);
  unique_prime.pop_back();

  std::vector<int> new_partial_result(partial_result);
  for (auto item : all_placement)
  {
    std::transform(partial_result.begin(), partial_result.end(), item.begin(), new_partial_result.begin(), std::multiplies<int>());
    cartesian_product(unique_prime, prime_placement, new_partial_result, final_result);
  }
}

// the number of ways to choose k elements from n elements
unsigned int C(int n, int k)
{
  if (k == 0 || k == n)
    return 1;
  unsigned int ans = 1;
  for (int i = 1; i <= k; i++)
  {
    ans = ans * (n - i + 1) / i; // Never shortened as *= because of integer division problem
  }
  return ans;
}

std::vector<int> precise_enumerate(int number, const std::vector<int> &launch_domain)
{
  // number can be regarded as #nodes
  int dim = launch_domain.size();
  std::vector<int> result;
  result.resize(dim, 1);
  if (number == 1)
  {
    return result;
  }
  // number = p1^a1 * p2^a2 * p3^a3 * ...
  // prime_factor[p_i] = a_i
  // unique_prime: p1, p2, ...
  std::unordered_map<int, int> prime2power;
  std::vector<int> unique_prime;
  generate_prime_factorization(number, prime2power, unique_prime);

  // prime_placement[p_i] records different ways to decompose {p_i}^{a_i} into {dim} places (each way is a {dim}-sized vector),
  std::unordered_map<int, std::vector<std::vector<int>>> prime_placement;
  unsigned int total_choices = 1;
  for (size_t i = 0; i < unique_prime.size(); i++)
  {
    int prime_num = unique_prime[i];
    int power = prime2power.at(prime_num);
    std::vector<std::vector<int>> ways;
    enumerate_placement(prime_num, power, dim, std::vector<int>(), ways);
    unsigned int num_ways = C(power + dim - 1, dim - 1);
    assert(ways.size() == num_ways);
    total_choices *= num_ways;
    prime_placement.insert({prime_num, ways});
  }
  // all possible ways to decompose {number} into {dim} places
  std::vector<std::vector<int>> choices;
  cartesian_product(unique_prime, prime_placement, std::vector<int>(result), choices);
  assert(choices.size() == total_choices);

  std::vector<std::vector<int>> all_results;

  float minimal = INT32_MAX;
  for (const auto &o_vec : choices)
  {
    std::vector<float> o_over_L = divide(o_vec, launch_domain);
    float cur = std::accumulate(o_over_L.begin(), o_over_L.end(), 0.0);
    if (fabs(cur - minimal) < 1e-6) // same overhead
    {
      all_results.push_back(o_vec);
    }
    else if (cur < minimal) // better result comes
    {
      minimal = cur;
      all_results.clear();
      all_results.push_back(o_vec);
    }
  }
  return all_results[0];
}

inline std::string myvec2str(const std::vector<int> &my_vector)
{
  std::stringstream result;
  std::copy(my_vector.begin(), my_vector.end(), std::ostream_iterator<int>(result, " "));
  return result.str();
}

inline std::string myvec2str(const std::vector<float> &my_vector)
{
  std::stringstream result;
  std::copy(my_vector.begin(), my_vector.end(), std::ostream_iterator<float>(result, " "));
  return result.str();
}

void printvec(const std::vector<int> &my_vector)
{
  std::cout << myvec2str(my_vector) << std::endl;
}

void printvec(const std::vector<float> &my_vector)
{
  std::cout << myvec2str(my_vector) << std::endl;
}

float judge(std::vector<std::vector<int>> candidates, std::vector<int> launch_space,
            int node_num = 0, int dx = 0, int dy = 0)
{
  float best_num = INT32_MAX;
  int best_idx = 0;
  std::vector<float> results;
  for (size_t i = 0; i < candidates.size(); i++)
  {
    // printf("Result:\n");
    // printvec(candidates[i]);
    std::vector<float> o_over_L = divide(candidates[i], launch_space);
    float minimize_target = std::accumulate(o_over_L.begin(), o_over_L.end(), 0.0); // Never use 0 to replace 0.0
    std::vector<float> L_over_o = divide(launch_space, candidates[i]); // workload vector
    float cur = minimize_target * std::accumulate(L_over_o.begin(), L_over_o.end(), 1.0, std::multiplies<float>());
    results.push_back(cur);
    if (cur <= best_num)
    {
      best_num = cur;
      best_idx = i;
    }
  }
  // assert(fabs(results[results.size()-1] - results[results.size()-2]) < 0.00001);
  float perc_improve = 0.0;
  #ifdef DEBUG_COMPARE
  for (size_t i = 0; i < results.size(); i++)
  {
    if (fabs(results[i] - best_num) > 0.000001)
    {
      printf("Find nonequal results for node_num = %d, launch_domain = (%d, %d)\n",
             node_num, dx, dy);
      printvec(results);
      printf("%d is worse, %lf - %lf = diff = %lf\n", (int)i, results[i], best_num, results[i] - best_num);
      printf("Optimal's orientation is from %d: ", best_idx);
      printvec(candidates[best_idx]);
      printf("Suboptimal's orientation is from %d:", (int)i);
      printvec(candidates[i]);
    }
  }
  #endif
  if (results[best_idx] < results[0])
  {
    float delta = results[0] - results[best_idx];
    perc_improve = delta / results[0];
  }
  // assert(best_idx == 3);
  assert(best_idx == 1);
  return perc_improve;
}


void test()
{
  int number = 2;
  std::vector<int> launch_domain = {1, 1, 1};
  auto res = precise_enumerate(number, launch_domain);
  auto res2 = greedy(number, launch_domain);
  printvec(res);
  printvec(res2);
}

void summary_test()
{
  std::vector<std::vector<int>> results;
  int improve_cnt = 0;
  float improve_perc_total = 0.0;
  float best_improve_perc = 0.0;
  int best_gpu_cnt, best_dx, best_dy;
  best_gpu_cnt = best_dx = best_dy = 0;
  int node_num_max, gpus_per_node;
  node_num_max = 64;
  gpus_per_node = 4;
  int total_cnt = 0;
  std::vector<float> improve_perc_res;
  // for (int gpu_num = 4; gpu_num <= node_num_max * gpus_per_node; gpu_num += gpus_per_node)
  // {
  //   for (int domain_x = 1; domain_x <= gpu_num; domain_x++)
  //   {
  //     if (gpu_num % domain_x != 0)
  //       continue;
  //     int domain_y = gpu_num / domain_x;
  for (int domain_x = 1; domain_x <= 256; domain_x++)
  {
    for (int domain_y = 1; domain_y <= 256; domain_y++)
    {
      if (domain_x * domain_y % 4 != 0)
        continue;
      int gpu_num = domain_x * domain_y;
      total_cnt++;
      std::vector<int> launch_domain = std::vector<int>{domain_x, domain_y};
      results.push_back(chapel_greedy(gpu_num, launch_domain));
      // results.push_back(greedy(node_num, launch_domain)); // Default Mapper's heursitics
      // results.push_back(brute_force(node_num, launch_domain, true)); // minimize maximal difference
      // results.push_back(brute_force(node_num, launch_domain, false)); // minimize real cost
      results.push_back(precise_enumerate(gpu_num, launch_domain)); // smarter algorithm to minimize cost
      float cur_improve_perc = judge(results, launch_domain, gpu_num, domain_x, domain_y);
      improve_perc_res.push_back(cur_improve_perc);
      if (cur_improve_perc > 0)
      {
        improve_cnt++;
        improve_perc_total += cur_improve_perc;
        if (cur_improve_perc > best_improve_perc)
        {
          best_improve_perc = cur_improve_perc;
          best_gpu_cnt = gpu_num;
          best_dx = domain_x;
          best_dy = domain_y;
        }
      }
      results.clear();
    }
  }
  printf("improve percentage= %d / %d = %lf, average improve perc = %lf,\
        best improve perc = %lf, coming from %d and (%d, %d)\n",
         improve_cnt, total_cnt, improve_cnt * 1.0 / total_cnt, improve_perc_total / improve_cnt,
         best_improve_perc, best_gpu_cnt, best_dx, best_dy);
  // write the values to a file with column: domain_x, domain_y, improve_percentage
  std::ofstream myfile;
  myfile.open("summary.csv");
  int idx = 0;
  // for (int gpu_num = 4; gpu_num <= node_num_max * gpus_per_node; gpu_num += gpus_per_node)
  // {
  //   for (int domain_x = 1; domain_x <= gpu_num; domain_x++)
  //   {
  //     if (gpu_num % domain_x != 0)
  //       continue;
  //     int domain_y = gpu_num / domain_x;
  for (int domain_x = 1; domain_x <= 256; domain_x++)
  {
    for (int domain_y = 1; domain_y <= 256; domain_y++)
    {
      if (domain_x * domain_y % 4 != 0)
        continue;
      myfile << domain_x << "," << domain_y << "," << improve_perc_res[idx] << "\n";
      idx++;
    }
  }
}

int main()
{
  summary_test();
  return 0;
}