#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>


cv::Mat exponential_function(cv::Mat channel, float exp){
  cv::Mat table(1, 256, CV_8U);
  for (int i = 0; i < 256; i++)
    table.at<uchar>(i) = cv::min((int)pow(i,exp),255);
  LUT(channel,table,channel);
  return channel;
}
void duo_tone(cv::Mat img){
  
  cv::namedWindow("image");
  int slider1 = 0;
  int slider2 = 1;
  int slider3 = 3;
  int slider4 = 0;

  std::string switch1  = "0 : BLUE n1 : GREEN n2 : RED";
  std::string switch2 = "0 : BLUE n1 : GREEN n2 : RED n3 : NONE";
  std::string switch3 = "0 : DARK n1 : LIGHT";
  cv::createTrackbar("exponent","image",&slider1,10);
  cv::createTrackbar(switch1,"image",&slider2,2);
  cv::createTrackbar(switch2,"image",&slider3,3);
  cv::createTrackbar(switch3,"image",&slider4,1);

  while(true){
    int exp1 = cv::getTrackbarPos("exponent","image");
    float exp = 1 + exp1/100.0;
    int s1 = cv::getTrackbarPos(switch1,"image");
    int s2 = cv::getTrackbarPos(switch2,"image");
    int s3 = cv::getTrackbarPos(switch3,"image");
    cv::Mat res = img.clone();
    cv::Mat channels[3];
    split(img,channels);
    for (int i=0; i<3; i++){
      if ((i == s1)||(i==s2)){
        channels[i] = exponential_function(channels[i],exp);
      }
      else{
        if (s3){
          channels[i] = exponential_function(channels[i],2-exp);
        }
        else{
          channels[i] = cv::Mat::zeros(channels[i].size(),CV_8UC1);
        }
      }
    }
    std::vector<cv::Mat> newChannels{channels[0],channels[1],channels[2]};
    merge(newChannels,res);
    imshow("Original",img);
    imshow("image",res);
    if (cv::waitKey(1) == 'q')
                        break;
                }
        cv::destroyAllWindows();
}
int main()
{
    cv::Mat image = cv::imread("C:/Users/PiroZHoCheck_2.0/Desktop/KOT.jpeg");
    duo_tone(image);
    cv::waitKey(0);
}