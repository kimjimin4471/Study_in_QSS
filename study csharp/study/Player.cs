using System;

namespace study
{
    public class Player : Characteristic
    {
        private int mp, def;

        public Player(int hp, int mp, int atk, int def, string name, int x, int y) : base(hp,atk,name, x, y)
        {
            this.mp = mp;
            this.def = def;
        }

        public void Heal(int using_mp)
        {
            this.mp -= using_mp;
            this.hp += using_mp / 2;
            Console.WriteLine("마나 "+using_mp + "사용하여 체력" + using_mp/2 + "회복\n\t현재 체력 "+ this.hp + "\n\n");
        }
    }
}