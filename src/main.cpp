// #include <windows.h>

// #include <stdio.h>
// #include <string>
// #include <vector>
// #include <iostream>
// #include <fstream>

// class GnuplotPipe {
// public:
//     inline GnuplotPipe(bool persist = true) {
//         std::cout << "Opening gnuplot... ";
//         pipe = popen(persist ? "gnuplot -persist" : "gnuplot", "w");
//         if (!pipe)
//             std::cout << "failed!" << std::endl;
//         else
//             std::cout << "succeded." << std::endl;
//     }

//     inline virtual ~GnuplotPipe(){
//         if (pipe) pclose(pipe);
//     }

//     void sendLine(const std::string& text, bool useBuffer = false){
//         if (!pipe) return;
//         if (useBuffer)
//             buffer.push_back(text + "\n");
//         else
//             fputs((text + "\n").c_str(), pipe);
//     }

//     void sendEndOfData(unsigned repeatBuffer = 1){
//         if (!pipe) return;
//         for (unsigned i = 0; i < repeatBuffer; i++) {
//             for (auto& line : buffer) fputs(line.c_str(), pipe);
//             fputs("e\n", pipe);
//         }
//         fflush(pipe);
//         buffer.clear();
//     }

//     void sendNewDataBlock(){
//         sendLine("\n", !buffer.empty());
//     }

//     void writeBufferToFile(const std::string& fileName){
//         std::ofstream fileOut(fileName);
//         for (auto& line : buffer) fileOut << line;
//         fileOut.close();
//     }

// private:
//     GnuplotPipe(GnuplotPipe const&) = delete;
//     void operator=(GnuplotPipe const&) = delete;

//     FILE* pipe;
//     std::vector<std::string> buffer;
// };

// int main(){
//     std::ofstream outfile ("gnuplot -persist",std::ofstream::out);
//     std::string a = "plot [-pi/2:pi] cos(x),-(sin(x) > sin(x+1) ? sin(x) : sin(x+1))";

//     outfile.write(a.c_str(), 10);
//     // GnuplotPipe gp;
//     // gp.sendLine("plot [-pi/2:pi] cos(x),-(sin(x) > sin(x+1) ? sin(x) : sin(x+1))");
//     // std::cin.get();
//     // gp.sendLine("plot cos(x)");
//     std::cin.get();
//     return 0;
// }
#include <boost/asio.hpp>
#include <boost/process.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace bp = boost::process;

int main()
{
   // bp::opstream ops;
   // bp::ipstream ips;

   // // boost::process::launch("", bp::std_out > ips, bp::std_in < ops);
   // bp::postream &os = c.get_stdin();
   // os << "plot cos(x)\n";
   // os.close();

   //    std::function<void(const boost::system::error_code & ec, std::size_t n)> on_stdin = [&]( const boost::system::error_code & ec, std::size_t n ){
   //         std::cout << "I know that " << n << " characters were sent to the process. Yay! " << std::endl;
   //     };
   // // std::vector<char> buf(4096);

   //     boost::asio::io_service ios;
   //     boost::process::async_pipe read_pipe{ios};
   //     boost::process::async_pipe write_pipe{ios};
   //     auto child_process = bp::child( "gnuplot -persist",
   //                                                 boost::process::std_in  <  write_pipe ,
   //                                                 boost::process::std_out >  read_pipe  );


   //    // write(s, boost::asio::buffer("GET / HTTP/1.1\r\n"
   //    //       "Host: 1.1.1.1\r\n"
   //    //       "Referer: stoackoverflow.com\r\n"
   //    //       "\r\n"));

   //    //  std::string write_string = "plot cos(x)\n";
   //    //   std::vector<char> vec(4096);
   //     boost::asio::async_write( write_pipe ,  boost::asio::buffer("plot cos(x)\r\n"),  on_stdin );
   //    ios.run();
   //    int result = child_process.exit_code();
   //   ios.poll();
   //     ios.restart();

   // pistream &is = c.get_stdout();
   // std::string str = "plot cos(x)\n";
   // ops << str.c_str();
   // std::string str;
   // ips >> str;

   // c.wait();







//    boost::process::pipe p = create_async_pipe();

//     boost::iostreams::file_descriptor_sink sink(p.sink, close_handle);
//     boost::process::execute(
//         boost::process::initializers::run_exe("gnuplot -persist"),
//         boost::process::initializers::bind_stdout(sink)
//     );

//     boost::iostreams::file_descriptor_source source(p.source(), close_handle);
// #define BOOST_WINDOWS_API
// #if defined(BOOST_WINDOWS_API)
//     typedef boost::asio::windows::stream_handle pipe_end;
// #elif defined(BOOST_POSIX_API)
//     typedef boost::asio::posix::stream_descriptor pipe_end;
// #endif

//     boost::asio::io_service io_service;

//     pipe_end pend(io_service, p._source);

//     boost::array<char, 4096> buffer;
//     boost::asio::async_read(pend, boost::asio::buffer(buffer),
//         [](const boost::system::error_code&, std::size_t){});

//     io_service.run();



   bp::opstream in;
   bp::ipstream out;
   bp::child c("gnuplot -persist", bp::std_out > bp::null, bp::std_in < in);
   in << "plot cos(x)" << endl;
   std::cin.get();
   in << "plot sin(x)" << endl;
   while (c.running());
   c.wait();
   c.terminate();
   return 0;
}