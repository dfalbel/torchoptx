#include <torch/torch.h>
#include <lantern/types.h>
#include "torchoptx/torchoptx_types.h"

namespace make_raw {
void* SGD (const optim_sgd& x) {
  return x;
}
void* Adam (const optim_adam& x) {
  return x;
}
}

namespace from_raw {
optim_sgd SGD (void* x) {
  return reinterpret_cast<optim_sgd>(x);
}
optim_adam Adam (void* x) {
  return reinterpret_cast<optim_adam>(x);
}
}

// [[torch::export]]
void delete_optim_sgd(void* x) {
  delete reinterpret_cast<optim_sgd>(x);
}

// [[torch::export]]
void delete_optim_adam(void* x) {
  delete reinterpret_cast<optim_adam>(x);
}
