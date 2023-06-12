#include <cstddef>
#include <iostream>
#include <optional>
#include <ranges>
#include <span>
#include <string>
#include <stdexcept>

struct Config {
  std::size_t number;
};

constexpr auto parse_args(const std::span<char *>& args) -> std::optional<Config> {
  if (args.size() != 2) {
    return {};
  }

  auto number_str = args[1];
  std::size_t number{};

  try {
    number = std::stoull(number_str);
  } catch (const std::invalid_argument&) {
    return {};
  }

  return Config{.number = number};
}

auto main(int argc, char *argv[]) -> int {
  std::span args{argv, static_cast<std::size_t>(argc)};
  auto maybe_config = parse_args(args);
  if (!maybe_config.has_value()) {
    std::cout << "USAGE: a.out <number>\n";
    return 1;
  }

  auto config = maybe_config.value();

  for (auto i : std::ranges::views::iota(0ull, config.number)) {
    std::cout << i << "\n";
  }
}

