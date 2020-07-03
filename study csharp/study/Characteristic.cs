using System;

namespace study
{
    public class Characteristic
    {
        private int atk, x, y;
        public string name;
        public int hp;
        
        public Characteristic(int hp, int atk, string name, int x = 0 , int y = 0 )
        {
            this.hp = hp;
            this.atk = atk;
            this.name = name;
            this.x = x;
            this.y = y;
        }

        public void Move(int x, int y)
        {
            this.x += x;
            this.y += y;
            Console.WriteLine("("+ this.x  + " , " + this.y +")에 이동");
        }

        public void Attack(Characteristic ntt)
        {
            ntt.hp -= this.atk;
            if (ntt.hp <= 0)
                ntt.hp = 0;
            Console.WriteLine( this.atk + "의 공격력으로 "+ ntt.name+"을(를) 공격\n\t"+ ntt.name + "의 체력이 " + ntt.hp + "남음\n\n");
        }

    }
}