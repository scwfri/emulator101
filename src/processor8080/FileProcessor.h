#ifndef EMULATOR101_FILEPROCESSOR_H
#define EMULATOR101_FILEPROCESSOR_H

class FileProcessor {
  public:
    FileProcessor() = delete;
    ~FileProcessor() = default;
    FileProcessor(const FileProcessor &) = delete;
    FileProcessor &operator=(const FileProcessor &) = delete;

  public:
    FileProcessor(const char *);
    int ProcessFile();

  private:
    const char *fname;
};

#endif // EMULATOR101_FILEPROCESSOR_H
