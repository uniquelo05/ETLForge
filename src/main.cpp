#include "cpp-taskflow/taskflow.hpp"
int main() {
  tf::Taskflow tf;
  tf::Executor executor;
  auto A = tf.emplace([]() { std::cout << "Task A\n"; });
  auto B = tf.emplace([]() { std::cout << "Task B\n"; });
  auto C = tf.emplace([]() { std::cout << "Task C\n"; });

  A.precede(B);
  A.precede(C);

  executor.run(tf).wait();
  return 0;
}