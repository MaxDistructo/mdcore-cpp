#include <string>
#include <vector>

namespace mdcore{
    namespace obj{
        class Command{
            public:
                Command();
                ~Command();
            private:
                std::string name;
                std::vector<std::string> altNames;
        };
    }
}