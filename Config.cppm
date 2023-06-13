module;

#include <cstddef>
#include <optional>
#include <span>
#include <string>

export module Config;

export class Config {
public:
  const std::size_t number = 0;

  /**
   * Construct from program arguments
   */
  static constexpr auto from_args(const std::span<char *> &args)
      -> std::optional<Config> {
    if (args.size() != 2) {
      return {};
    }

    const auto number_str = args[1];
    std::size_t number{};
    try {
      number = std::stoull(number_str);
    } catch (const std::invalid_argument &) {
      return {};
    }

    return Config{.number = number};
  }
};
