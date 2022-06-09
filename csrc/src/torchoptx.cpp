#include <torch/torch.h>
#define LANTERN_TYPES_IMPL // Should be defined only in a single file.
#include <lantern/types.h>
#include <iostream>
#include <vector>
#include "torchoptx/torchoptx.h"
#include "torchoptx/torchoptx_types.h"

// [[torch::export(register_types=c("optim_sgd", "SGD", "void*", "torchoptx::optim_sgd"))]]
optim_sgd torchoptx_sgd(torch::TensorList params) {
 return new torch::optim::SGD(params.vec(), 0.1);
}

// [[torch::export]]
void torchoptx_sgd_step(optim_sgd opt) {
  opt->step();
}

// [[torch::export]]
void torchoptx_sgd_zero_grad(optim_sgd opt) {
  opt->zero_grad();
}

// [[torch::export(register_types=c("optim_adam", "Adam", "void*", "torchoptx::optim_adam"))]]
optim_adam torchoptx_adam(torch::TensorList params) {
  return new torch::optim::Adam(params.vec(), 0.1);
}

// [[torch::export]]
void torchoptx_adam_step(optim_adam opt) {
  opt->step();
}

// [[torch::export]]
void torchoptx_adam_zero_grad(optim_adam opt) {
  opt->zero_grad();
}

