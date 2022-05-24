#include <iostream>
#include <list>

class YoutubeChannel {
private:
    std::string Name;
    std::string OwnerName;
    int SubscribersCount;
    std::list<std::string> PublishedVideoTitles;
public:
    YoutubeChannel(std::string name, std::string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;

    }

    void GetInfo(){
        std::cout << "Name:  " << Name << std::endl;
        std::cout << "Owner Name:  " << OwnerName << std::endl;
        std::cout << "Subscriber Count:  " << SubscribersCount << std::endl;
        std::cout << "Videos: " << std::endl;   
        for (std::string videotitle: PublishedVideoTitles){
            std::cout << videotitle << std::endl;
        }
    }

    void Subscribe() {
        SubscribersCount++;
    }

    void Unsub(){
        if(SubscribersCount > 0)
            SubscribersCount--;
    }

    void PublishVideo(std::string title){
        PublishedVideoTitles.push_back(title);
    }
};

class CookingYoutubeChannel:public YoutubeChannel {
public:
    CookingYoutubeChannel(std::string name, std::string ownerName):YoutubeChannel(name, ownerName) {
    
    }
    
};


int main()
{

    YoutubeChannel myYTchannel("Smigymuller", "Alex Bennett");
    myYTchannel.PublishVideo("Anthonys big fall");
    myYTchannel.PublishVideo("Big big fall");
    myYTchannel.PublishVideo("3 stair ollie");

    myYTchannel.Subscribe();
    myYTchannel.Subscribe();
    myYTchannel.Subscribe();
    myYTchannel.Unsub();
    
    
    YoutubeChannel YTchannel2("AmySings", "Amy");
    YTchannel2.PublishVideo("Bladee Cover 1");
    YTchannel2.PublishVideo("Bladee Cover 2");
   
    myYTchannel.GetInfo();
    YTchannel2.GetInfo();
    
    CookingYoutubeChannel ytChannel("Babs Cooking", "Barbara");
    ytChannel.PublishVideo("Apple Pie");
    ytChannel.PublishVideo("Chocolate Cake");
    ytChannel.GetInfo();

  

    return 0;
}