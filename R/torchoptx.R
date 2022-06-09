#' @export
optim_sgd <- torch::optimizer(
  "optim_sgd",
  initialize = function(params) {
    self$opt <- optim_sgd_new(params)
  },
  step = function() {
    optim_sgd_step(self$opt)
  },
  zero_grad = function() {
    optim_sgd_zero_grad(self$opt)
  }
)
