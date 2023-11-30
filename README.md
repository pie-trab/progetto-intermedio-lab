ITA
-----------------------
Progetto intermedio laboratorio di programmazione
================

Gruppo: Nicolò Fioranzato, Pietro Trabuio
-----------------------

Classe Book
-----------------------
La classe Book implementa un libro e i metodi per gestirne prestito e restituzione. 
Tra i campi presenti, oltre a quelli richiesti è presente una data _return_date che rappresenta 
la data entro cui dovrà essere restituito (decisa nella funzione reserve_book, di default noi abbiamo scelto un mese).
La funzione reserve_book inoltre esegue un controllo sulla data in input per verificare se 
il libro è attualmente in prestito o in ritardo con la restituzione.
Il metodo return_book consente di restituire un libro, inserendo la data di restituzione in input,
permette di sapere se è stato restituito in tempo o meno.
Per controllare la validità dell'isbn viene eseguito un semplice controllo sulla lunghezza della stringa (lunghezza 13 caratteri).
Sono presenti diversi costruttori, tra cui quello di default, quello richiesto dalla specifica del problema, 
ossia un costruttore parametrico che permette di inizializzare un libro senza avere nota la data di copyright,
e il costruttore che permette di inizializzare anche la data di copyright.

Classe BookShelf
-----------------------
La classe BookShelf permette di gestire vettori di Book tramite allocazione dinamica della memoria.
Sono stati implementati i costruttori di copia, di movimento, e operatori di copia e di movimento e il distruttore. 
Abbiamo inoltre implementato i metodi push_back e pop_back che permettono l’inserimento e la rimozione di un libro alla fine del vettore. 
Il tutto è implementato in maniera dinamica tendo conto della dimensione del buffer, riservando nuova memoria all’occorrenza tramite il metodo reserve. 
Oltre ai costruttori citati in precedenza sono presenti il costruttore di default, per la creazione di una BookShelf di capacità 1 inizialmente vuota,
un costruttore che permette la creazione di una BookShelf di capacità n passata in input e il costruttore
che permette la creazione di una nuova BookShelf tramite un’initializer_list.

Classe Date
-----------------------
La classe Date implementa una data tramite tre parametri: due interi per anno e giorno e un Enum per il mese. 
è presente un costruttore parametrico per l’inizializzazione dei parametri in ordine anno, mese, giorno,
un costruttore di default, che inizializza la data al 1/1/1. Sono presenti diversi metodi per la gestione delle date,
tra cui add di giorno, mese ed anno, che permettono l’incremento di n giorni, mesi o anni, specificato in input. 
È presente un override dell’operatore <<, e dei metodi di confronto tra due date.

Classe Exception
-----------------------
La classe Exception rappresenta una semplice eccezione che permette di lanciare un oggetto Exception con un messaggio di errore personalizzato. 

main:
-----------------------
Sono presenti i test di tutti i metodi e costruttori della classe Book e BookShelf, dove tramite standard output viene stampato l’esito di ogni test. 
I test sono stati separati in diverse funzioni, poi richiamate nel main, per una maggiore modularità. 
Per testare il costruttore e operatore di movimento della classe BookShelf abbiamo inserito delle stampe a standard output per segnalare la loro invocazione.
Qualora si vogliano testare tali costruttore e operatore di assegnamento sarà opportuno forzare il compilatore al loro utilizzo
tramite l’opzione “-fno-elide-constructors”, ciò è possibile togliendo il commento dall’opzione nel file CMakeLists.txt del progetto.



-----------------------
-----------------------
ENG
-----------------------
Intermediate project programming laboratory
=======================

Group: Nicolò Fioranzato, Pietro Trabuio
-----------------------

Class Book
-----------------------
The Book class implements a book and the methods to manage its reserve and return. 
Among the fields present, in addition to those required there is a date _return_date that represents the date by which it must be returned
(decided in the function reserve_book, by default we chose a month).
The reserve_book function also performs a check on the input date to check whether the book is currently on reserve or late for the return.
The return_book method allows you to return a book, entering the date of return in input, lets you know if it was returned on time or not.
To check the validity of the isbn, a simple check is done on the length of the string (length 13 characters).
There are several constructors, including the default one, the one required by the specification of the problem,
and a parametric constructor that allows you to initialize a book without having the copyright date,
and the constructor that allows to initialize also the date of copyright.

The BookShelf class:
-----------------------
The BookShelf class allows to manage Book vectors through dynamic memory allocation. The copy and move constructors, 
copy and move operators and the destroyer are implemented. We have also implemented push_back and pop_back methods that
allow the insertion and removal of a Book at the end of the vector. This is implemented in a dynamic way, considering the size of the buffer,
reserving new memory, if necessary, through the reserve method. In addition to the above mentioned constructors there is the default constructor,
for the creation of a BookShelf of capacity 1 initially empty, a constructor that allows the creation of a BookShelf
of n input capacity and the constructor that allows the creation of a new BookShelf through an initializer_list.

Class Date
-----------------------
The Date class implements a date using three parameters: two integers for year and day and one Enum for the month. 
There is a parametric constructor for initialization of parameters in order year, month, day; a default constructor,
which initializes the date to 1/1/1. There are several methods for managing dates, including day, month and year add,
which allow the increase of n days, months or years, specified in input. There is an override of the <<operator, 
and methods of comparing two dates.

Exception Class
-----------------------
The Exception class is a simple exception that allows you to launch an Exception object with a custom error message.

main:
-----------------------
There are tests of all the methods and constructors of the class Book and BookShelf, where in the standard out is printed the result of each test.
The tests were separated in several functions, then invoked in the main, for greater modularity.
To test the constructors and movement operators of the BookShelf class we have inserted standard output prints to signal their invocation.
If you want to test these constructors and assignment operators, you should force the compiler to use them with the "-fno-elide-constructors" option,
removing the comment from the option in the CMakeLists.txt file of the project.





