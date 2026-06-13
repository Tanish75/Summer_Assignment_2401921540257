package music;

public interface Playable {
    void play();
}


package music.string;

import music.Playable;

public class Veena implements Playable 
{
    @Override
    public void play() 
{
        System.out.println("Playing Veena... (String instrument)");
    }
}

package music.wind;

import music.Playable;

public class Saxophone implements Playable 
{
    @Override
    public void play() 
{
        System.out.println("Playing Saxophone... (Wind instrument)");
    }
}

package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {
    public static void main(String[] args) 
{

        // a. Veena instance
        Veena veena = new Veena();
        veena.play();

        // b. Saxophone instance
        Saxophone saxophone = new Saxophone();
        saxophone.play();

        // c. Playable reference (Polymorphism)
        Playable p1 = new Veena();
        p1.play();

        Playable p2 = new Saxophone();
        p2.play();
    }
}
