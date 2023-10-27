#include "../../../include/metadata/Schema.h"
namespace demo {
   Schema::Schema(const std::vector<Column> &columns) {

    }
    auto Schema::GetColumns() const -> const std::vector<Column> & {
        static const std::vector<Column> defaultColumns;
        return defaultColumns;
    }

    auto Schema::GetColumn(const uint32_t col_idx) const -> const Column & {
        // Return a default Column object for testing
        static const Column defaultColumn;
        return defaultColumn;
    }

    auto Schema::GetColIdx(const std::string &col_name) const -> uint32_t {
        // Return 0 as a default column index for testing
        return 0;
    }

    // Uncomment this function if you want to implement it.
    // auto TryGetColIdx(const std::string &col_name) const -> std::optional<uint32_t>;

    auto Schema::GetUnlinedColumns() const -> const std::vector<uint32_t> & {
        static const std::vector<uint32_t> defaultUnlinedColumns;
        return defaultUnlinedColumns;
    }

    auto Schema::GetColumnCount() const -> uint32_t {
        // Return 0 as the default column count for testing
        return 0;
    }

    auto Schema::GetUnlinedColumnCount() const -> uint32_t {
        // Return 0 as the default unlined column count for testing
        return 0;
    }

     auto Schema::GetLength() const -> uint32_t {
        // Return 0 as the default length for testing
        return 0;
    }

    inline auto Schema::IsInlined() const -> bool {
        // Return false as the default value for testing
        return false;
    }

    auto Schema::ToString(bool simplified ) const -> std::string {
        // Return an empty string as the default representation for testing
        return "";
    }

}