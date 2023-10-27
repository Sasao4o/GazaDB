#ifndef ColumnHeader
#define ColumnHeader

namespace demo {
    class Column {
        public:
        bool IsInlined() const {
            return true;
        }
        int GetOffset() const {
            return 0;
        }
    };
}

#endif