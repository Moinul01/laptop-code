
package busresevationsystem;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Bus {
    String busNumber;
    boolean isAC;
    int totalSeats;
    int availableSeats;

    public Bus(String busNumber, boolean isAC, int totalSeats) {
        this.busNumber = busNumber;
        this.isAC = isAC;
        this.totalSeats = totalSeats;
        this.availableSeats = totalSeats;
    }

    public boolean isAvailable(int seats) {
        return availableSeats >= seats;
    }

    public void bookSeats(int seats) {
        if (isAvailable(seats)) {
            availableSeats -= seats;
            System.out.println(seats + " seats booked successfully on bus " + busNumber);
        } else {
            System.out.println("Seats not available on bus " + busNumber);
        }
    }

    public void cancelSeats(int seats) {
        if (availableSeats + seats <= totalSeats) {
            availableSeats += seats;
            System.out.println(seats + " seats canceled on bus " + busNumber);
        } else {
            System.out.println("Invalid number of seats to cancel on bus " + busNumber);
        }
    }
}

public class BusReservationSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize buses
        Bus bus1 = new Bus("BUS101", true, 40);
        Bus bus2 = new Bus("BUS102", false, 30);

        System.out.println("Welcome to the Bus Reservation System");

        while (true) {
            System.out.println("\nSelect an option:");
            System.out.println("1. Book a ticket");
            System.out.println("2. Cancel a ticket");
            System.out.println("3. Exit");
            int choice = scanner.nextInt();

            if (choice == 1) {
                System.out.println("Available buses:");
                System.out.println("1. AC Bus (" + bus1.availableSeats + " seats available)");
                System.out.println("2. Non-AC Bus (" + bus2.availableSeats + " seats available)");
                int busChoice = scanner.nextInt();
                Bus selectedBus = (busChoice == 1) ? bus1 : bus2;

                System.out.print("Enter the number of seats to reserve: ");
                int seatsToBook = scanner.nextInt();

                if (selectedBus.isAvailable(seatsToBook)) {
                    selectedBus.bookSeats(seatsToBook);
                } else {
                    System.out.println("Desired number of seats not available on selected bus.");
                }
            } else if (choice == 2) {
                System.out.println("Select bus for cancellation:");
                System.out.println("1. AC Bus");
                System.out.println("2. Non-AC Bus");
                int busChoice = scanner.nextInt();
                Bus selectedBus = (busChoice == 1) ? bus1 : bus2;

                System.out.print("Enter the number of seats to cancel: ");
                int seatsToCancel = scanner.nextInt();
                selectedBus.cancelSeats(seatsToCancel);
            } else if (choice == 3) {
                System.out.println("Thank you for using the Bus Reservation System!");
                break;
            } else {
                System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }
}
