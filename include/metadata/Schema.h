 
#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>
#include "../storage/table/Column.h"
 
namespace demo {

 

class Schema {
 public:
 
  explicit Schema(const std::vector<Column> &columns);
  auto GetColumns() const -> const std::vector<Column> &;  
  auto GetColumn(const uint32_t col_idx) const -> const Column &;
  auto GetColIdx(const std::string &col_name) const -> uint32_t;
  // auto TryGetColIdx(const std::string &col_name) const -> std::optional<uint32_t>;
  auto GetUnlinedColumns() const -> const std::vector<uint32_t> &;
  auto GetColumnCount() const -> uint32_t;
  auto GetUnlinedColumnCount() const -> uint32_t;
   auto GetLength() const -> uint32_t;
  inline auto IsInlined() const -> bool;
  auto ToString(bool simplified = true) const -> std::string;
 private:
 
  uint32_t length_;

 
  std::vector<Column> columns_;

  
  bool tuple_is_inlined_{true};

 
  std::vector<uint32_t> uninlined_columns_;
};

}   

// template <typename T>
// struct fmt::formatter<T, std::enable_if_t<std::is_base_of<bustub::Schema, T>::value, char>>
//     : fmt::formatter<std::string> {
//   template <typename FormatCtx>
//   auto format(const bustub::Schema &x, FormatCtx &ctx) const {
//     return fmt::formatter<std::string>::format(x.ToString(), ctx);
//   }
// };

// template <typename T>
// struct fmt::formatter<std::shared_ptr<T>, std::enable_if_t<std::is_base_of<bustub::Schema, T>::value, char>>
//     : fmt::formatter<std::string> {
//   template <typename FormatCtx>
//   auto format(const std::shared_ptr<T> &x, FormatCtx &ctx) const {
//     if (x != nullptr) {
//       return fmt::formatter<std::string>::format(x->ToString(), ctx);
//     }
//     return fmt::formatter<std::string>::format("", ctx);
//   }
// };

// template <typename T>
// struct fmt::formatter<std::unique_ptr<T>, std::enable_if_t<std::is_base_of<bustub::Schema, T>::value, char>>
//     : fmt::formatter<std::string> {
//   template <typename FormatCtx>
//   auto format(const std::unique_ptr<T> &x, FormatCtx &ctx) const {
//     if (x != nullptr) {
//       return fmt::formatter<std::string>::format(x->ToString(), ctx);
//     }
//     return fmt::formatter<std::string>::format("", ctx);
//   }
// };
