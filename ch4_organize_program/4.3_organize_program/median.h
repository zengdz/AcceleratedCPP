#ifndef GUARD_median_h
#define GUARD_median_h
#include <vector>
// 形参要使用vector，使用std::vector而非using
// 这样可以引入最少的内容，给用户保留最大限度灵活性
double median(std::vector<double>);

#endif // !GUARD_median_h

