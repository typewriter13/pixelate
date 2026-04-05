#include <iostream>
#include <opencv2/opencv.hpp>
#include "convolution.hpp"


using namespace std;

int main()
{
        cv::Mat input = cv::imread("./assets/hogwarts.png", cv::IMREAD_GRAYSCALE);
    if (input.empty()) {
        cerr << "Could not load image at ./assets/hogwarts.png\n";
        return -1;
    }
     // Read input image
    /*std::string input_path = "task1/assets/hogwarts.png";
    cv::Mat input = cv::imread(input_path, cv::IMREAD_COLOR);        // Read colored image 8*/
        cv::Mat img_f;
        cv::Mat img_f2;

        cv::Mat img_f3;
        cv::Mat img_f4;
        cv::Mat img_f5;

    input.convertTo(img_f, CV_64FC1);
 

    // cv::Mat input = cv::imread(input_path, cv::IMREAD_GRAYSCALE); // Read grayscale image
    // Declare the output image matrix
    // Resize the input image to a more manageable size for demonstration purposes
    cv::resize(input, input, cv::Size(input.cols*0.5, input.rows*0.5));

    cv::Mat output1;
    cv::Mat output2;
    std::cout << "Demonstrating separable convolutions...\n";

    // The two kernels — do not change these
    cv::Mat K1 = (cv::Mat_<double>(3, 3) <<
         1,  2,  1,
         0,  0,  0,
        -1, -2, -1
    );

    cv::Mat K2 = (cv::Mat_<double>(3, 3) <<
         1,  0, -1,
         2,  0, -2,
         1,  0, -1
    );

    cv::Mat gaussian_v1 = (cv::Mat_<double>(3, 1) << 1.0 , 0.0 , -1.0);
    cv::Mat gaussian_h1= (cv::Mat_<double>(1, 3) <<  1.0 , 2.0 , 1.0);
    cv::Mat gaussian_v2 = (cv::Mat_<double>(3, 1) << 1.0 , 2.0 , 1.0);
    cv::Mat gaussian_h2= (cv::Mat_<double>(1, 3) <<  1.0 , 0.0 , -1.0);
    // Making All Windows resizable
    /*cv::namedWindow("Output", cv::WINDOW_NORMAL);
    cv::imshow("Output", output);
    cv::waitKey(0); // Wait for key press before moving to the next image*/


    // Declare matrix to store intermediate image
    cv::Mat intermediate1;
    
    cv::Mat intermediate2;
    

    // Now to actually convolve
    intermediate1 = convolve(img_f, gaussian_v1);    
    intermediate1.convertTo(img_f2, CV_64FC1);     // Convolve Vertically
    output1 = convolve(intermediate1, gaussian_h1);  
    output1.convertTo(img_f4, CV_64FC1);      // Convolve Horizontally
    intermediate2 = convolve(output1, gaussian_v2);   
    intermediate2.convertTo(img_f3, CV_64FC1);      // Convolve Vertically
    output2 = convolve(intermediate2, gaussian_h2);  
    output2.convertTo(img_f5, CV_64FC1);

    cv::namedWindow("Output by Naive Seperable Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output by Naive Seperable Convolution", output2);
    cv::waitKey(0); // Wait for key press before moving to the next image
     // Define decomposed standard 3x3 Gaussian kernel


    /*cv::namedWindow("Output of Vertical Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Vertical Convolution", intermediate);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Horizontal Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Horizontal Convolution", output);
    cv::waitKey(0); // Wait for key press before exiting
*/







    // TODO: apply K1 and K2 to img_f with as few multiplications per pixel as possible.
    // Print the number of multiplications your approach uses per pixel.

    return 0;
}
/*#include <opencv2/opencv.hpp>
#include <iostream>
#include "convolution.hpp"     // Our naive implementation of the convolution operation
mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
int main()
{

    // Read input image
    std::string input_path = "./assets/Dog_img.jpeg";
    cv::Mat input = cv::imread(input_path, cv::IMREAD_COLOR);        // Read colored image
    // cv::Mat input = cv::imread(input_path, cv::IMREAD_GRAYSCALE); // Read grayscale image

    // Resize the input image to a more manageable size for demonstration purposes
    cv::resize(input, input, cv::Size(input.cols*0.5, input.rows*0.5));

    // Declare the output image matrix
    cv::Mat output;
    std::cout << "Demonstrating separable convolutions...\n";

    // Define standard 3x3 Gaussian kernel
    cv::Mat gaussian = (cv::Mat_<double>(3, 3) <<
        1. / 16, 2. / 16, 1. / 16,
        2. / 16, 4. / 16, 2. / 16,
        1. / 16, 2. / 16, 1. / 16
    );

    filter2D(input, output, -1, gaussian);              // Convolve with original 'full' kernel

    // Making All Windows resizable
    cv::namedWindow("Output", cv::WINDOW_NORMAL);
    cv::imshow("Output", output);
    cv::waitKey(0); // Wait for key press before moving to the next image

    // Define decomposed standard 3x3 Gaussian kernel
    cv::Mat gaussian_v = (cv::Mat_<double>(3, 1) << 1. / 4, 1. / 2, 1. / 4);
    cv::Mat gaussian_h = (cv::Mat_<double>(1, 3) << 1. / 4, 1. / 2, 1. / 4);

    // Declare matrix to store intermediate image
    cv::Mat intermediate;

    // Now to actually convolve
    intermediate = convolve(input, gaussian_v);         // Convolve Vertically
    output = convolve(intermediate, gaussian_h);        // Convolve Horizontally

    cv::namedWindow("Output by Naive Seperable Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output by Naive Seperable Convolution", output);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Vertical Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Vertical Convolution", intermediate);
    cv::waitKey(0); // Wait for key press before moving to the next image

    cv::namedWindow("Output of Horizontal Convolution", cv::WINDOW_NORMAL);
    cv::imshow("Output of Horizontal Convolution", output);
    cv::waitKey(0); // Wait for key press before exiting

    return 0;
}
    */
