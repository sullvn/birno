#include <cstddef>
#include <iostream>
#include <ranges>
#include <span>

import Config;

auto main(int argc, char *argv[]) -> int {
  std::span args{argv, static_cast<std::size_t>(argc)};

  auto maybe_config = Config::from_args(args);
  if (!maybe_config.has_value()) {
    std::cout << "USAGE: a.out <number>\n";
    return 1;
  }

  auto config = maybe_config.value();

  for (auto i : std::ranges::views::iota(0ull, config.number)) {
    std::cout << i << "\n";
  }
}

