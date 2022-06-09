#include <torch/torch.h>

using optim_sgd = torch::optim::SGD*;

namespace make_raw {
void* SGD (const optim_sgd& x);
}

namespace from_raw {
optim_sgd SGD (void* x);
}
