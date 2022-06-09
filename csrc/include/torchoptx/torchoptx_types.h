#include <torch/torch.h>

using optim_sgd = torch::optim::SGD*;
using optim_adam = torch::optim::Adam*;

namespace make_raw {
void* SGD (const optim_sgd& x);
void* Adam (const optim_adam& x);
}

namespace from_raw {
optim_sgd SGD (void* x);
optim_adam Adam (void* x);
}
