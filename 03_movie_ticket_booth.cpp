#include <iostream>
#include <string>
using namespace std;

/* Movie ticket counter booth --
    1. Ask for the customer's name
    2. Display a list of movies
    3. Check ticket eligibility based on age
    4. Ask for purchases
    5. Apply discount
    6. Display final receipt
*/

int main(){

    // Movie times
    string kidTime{"10:00 AM"};
    string teenTime{"5:30 PM"};
    string adultTime{"9:30 PM"};

    // Cost of items
    int costTicket{200};
    int costPopcorn{60};
    int costColdrink{30};
    int costWaterbottle{10};

    // Customer details
    string customerName{};
    int movieChoice{};
    int customerAge{};

    // Customer purchases
    int boughtTickets{};
    int boughtPopcorn{};
    int boughtColdrink{};
    int boughtWaterbottle{};

    // Taking user details
    cout << "Enter your name kindly: ";
    getline(cin, customerName);

    cout << "Enter your age: ";
    cin >> customerAge;

    bool isAdult{customerAge >= 18};
    bool isTeen{customerAge >= 16 and customerAge < 18};
    bool isKid{customerAge >= 12 and customerAge < 16};

    // Movie selection
    cout << "\n\n";
    cout << "===== MOVIE TICKET BOOTH =====" << '\n'
         << "1. Interstellar" << '\n'       // 12+
         << "2. Spider-Man" << '\n'          // 16+
         << "3. The Dark Knight" << '\n';    // 18+

    cout << "\n";
    cout << "Which movie do you want to watch?: ";
    cin >> movieChoice;

    cout << "\n";

    // Movie names
    string movieName{};

    if(movieChoice == 1){
        movieName = "Interstellar";
    }

    else if(movieChoice == 2){
        movieName = "Spider-Man";
    }

    else if(movieChoice == 3){
        movieName = "The Dark Knight";
    }

    else{
        cout << "Invalid movie choice!\n";
    }

    // Checking age requirements
    bool canWatch{false};
    string showTime{};

    if (isAdult and
        (movieChoice == 1 or
         movieChoice == 2 or
         movieChoice == 3)){

        showTime = adultTime;
        canWatch = true;
    }

    else if (isTeen and
             (movieChoice == 1 or
              movieChoice == 2)){

        showTime = teenTime;
        canWatch = true;
    }

    else if (isKid and movieChoice == 1){

        showTime = kidTime;
        canWatch = true;
    }

    else if(movieChoice >= 1 and movieChoice <= 3){

        cout << "You do not match the requirements to watch this film!\n";
    }

    // Purchase section
    if(canWatch){

        cout << "You can watch " << movieName
             << " at " << showTime
             << ". Enjoy your movie!\n";

        cout << "\nHow many tickets do you want to purchase?: "
             << "\nYou get a 10% discount on purchase of 3+ tickets!!: ";
        cin >> boughtTickets;

        cout << "\nHow many cold drinks do you want to purchase?: ";
        cin >> boughtColdrink;

        cout << "\nHow many popcorn packets do you want to purchase?: ";
        cin >> boughtPopcorn;

        cout << "\nHow many water bottles do you want to purchase?: ";
        cin >> boughtWaterbottle;


        // Total price of purchased items
        int totalcostTicket{boughtTickets * costTicket};
        int totalCostColddrink{boughtColdrink * costColdrink};
        int totalCostPopcorn{boughtPopcorn * costPopcorn};
        int totalCostWaterBottle{boughtWaterbottle * costWaterbottle};

        int subTotal{
            totalcostTicket +
            totalCostColddrink +
            totalCostPopcorn +
            totalCostWaterBottle
        };


        // Discount calculations
        double discountedTicketPrice{
            costTicket - (costTicket * 0.10)
        };

        double totalDiscountedTicketPrice{0};
        double totalDiscount{0};

        if(boughtTickets >= 3){

            totalDiscountedTicketPrice =
                discountedTicketPrice * boughtTickets;

            totalDiscount =
                totalcostTicket - totalDiscountedTicketPrice;
        }


        // Final cost
        double finalTotal{subTotal - totalDiscount};


        // Purchase receipt
        cout << "\n\n";
        cout << "========================================\n";
        cout << "           MOVIE TICKET RECEIPT\n";
        cout << "========================================\n\n";

        cout << "Customer Name : " << customerName << '\n';
        cout << "Customer Age  : " << customerAge << '\n';
        cout << "Movie         : " << movieName << '\n';
        cout << "Show Time     : " << showTime << '\n';

        cout << "\n----------------------------------------\n";
        cout << "           PURCHASE DETAILS\n";
        cout << "----------------------------------------\n\n";

        cout << "Tickets       : " << boughtTickets
             << " x Rs." << costTicket << '\n';

        if(boughtTickets >= 3){

            cout << "Discount      : 10%\n";
            cout << "Discount Saved: Rs." << totalDiscount << '\n';
        }

        else{

            cout << "Discount      : 0%\n";
            cout << "Discount Saved: Rs.0\n";
        }

        cout << '\n';

        cout << "Popcorn       : " << boughtPopcorn
             << " x Rs." << costPopcorn << '\n';

        cout << "Cold Drinks   : " << boughtColdrink
             << " x Rs." << costColdrink << '\n';

        cout << "Water Bottles : " << boughtWaterbottle
             << " x Rs." << costWaterbottle << '\n';

        cout << "\n----------------------------------------\n";
        cout << "             BILL SUMMARY\n";
        cout << "----------------------------------------\n\n";

        cout << "Subtotal      : Rs." << subTotal << '\n';
        cout << "Total Discount: Rs." << totalDiscount << '\n';
        cout << "TOTAL COST    : Rs." << finalTotal << '\n';

        cout << "\n========================================\n";
        cout << "        THANK YOU FOR VISITING!\n";
        cout << "           ENJOY YOUR MOVIE!\n";
        cout << "========================================\n";
    }

    return 0;
}
