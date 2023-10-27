  #include<string>
  #include <fstream>
  #include<iostream>
  #include <sys/stat.h>
  #include<cstring>
  namespace demo {
  
    class DiskManager {
        public:
        explicit DiskManager(std::string fileName, int pageSize);
        void ReadPage(int pageId,char *pageData);  
        void WritePage(int pageId, const char *pageData);   
        int GetFileSize();
        private:
        std::fstream dbIo;
        std::string fileName;
        int pageSize;

    };












  }