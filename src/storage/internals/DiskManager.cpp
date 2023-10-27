      #include<string>
      #include "../../../include/storage/internals/DiskManager.h"
  namespace demo {
  
  
         
         DiskManager::DiskManager(std::string fileName, int pageSize) {
            this->fileName = fileName;
            this->pageSize = pageSize;
            std::string::size_type n = fileName.rfind('.');
            if (n == std::string::npos) {
               throw  "wrong file format";
                return;
            }
            dbIo.open(fileName, std::ios::binary | std::ios::in | std::ios::out);
            //This line means i wanna open the file in binary mode and im going read and write
              if (!dbIo.is_open()) {
                dbIo.clear();
                dbIo.open(fileName, std::ios::binary | std::ios::trunc | std::ios::out | std::ios::in);
                //Truncate means i will open a file and start writing from empty initial state
                if (!dbIo.is_open()) {
                throw  "can't open db file";
                }
            }
        }

            void DiskManager::ReadPage(int pageId,char *pageData) {
            int offset = pageId * pageSize;
            // check if read beyond file length
            if (offset > GetFileSize()) {
                // LOG_DEBUG("I/O error reading past end of file");
                throw "I/O error reading past end of file";
                // std::cerr << "I/O error while reading" << std::endl;
            } else {
                // set read cursor to offset
                dbIo.seekp(offset);
                dbIo.read(pageData, pageSize);
                if (dbIo.bad()) {
                // LOG_DEBUG("I/O error while reading");
                throw "Io Error While Reading";
                return;
                }
                // if file ends before reading BUSTUB_PAGE_SIZE
                int readCount = dbIo.gcount();
                if (readCount < pageSize) {
                // LOG_DEBUG("Read less than a page");
                std::cout << "Read Less Than a Page";
                dbIo.clear();
                // std::cerr << "Read less than a page" << std::endl;
                memset(pageData + readCount, 0, pageSize - readCount);
                }
            }
            }
 
            int DiskManager::GetFileSize()  {
                struct stat stat_buf;
                int rc = stat(fileName.c_str(), &stat_buf);
                 return rc == 0 ? static_cast<int>(stat_buf.st_size) : -1;
                }


            void DiskManager::WritePage(int pageId, const char *pageData) {
                int offset =  pageId * pageSize;
                
                dbIo.seekp(offset);
                dbIo.write(pageData, pageSize);
                // check for I/O error
                if (dbIo.bad()) {
                    throw "I/O error while writing";
                    return;
                }
                // needs to flush to keep disk file in sync
                dbIo.flush();
                }









  }