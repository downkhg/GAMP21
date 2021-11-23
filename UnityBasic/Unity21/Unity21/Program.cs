using System;
using System.Collections.Generic;

namespace Unity21
{
    //추상화
    //속성: hp, atk -> 변수
    //동작: 공격 -> 대상의 hp를 감소시킨다., 죽었다: hp가 0이된다.
    class Player
    {
        string name = "test";
        int hp = 100;
        int atk = 10;

        public Player(string _name, int _hp, int _atk)
        {
            name = _name;
            hp = _hp;
            atk = _atk;
        }

        public void Attack(Player target)
        {
            //target.hp -= atk;
            target.hp = target.hp - atk;
        }

        public bool Death()
        {
            if (hp <= 0)
                return true;
            else
                return false;
        }

        public void Show()
        {
            Console.WriteLine("######" + name + "#######");
            Console.WriteLine("HP:" + hp);
            Console.WriteLine("ATK:" + atk);
        }
    }

    class Program
    {
        //몬스터와 플레이어를 싸우게 만들어서 한쪽이 쓰러질때까지 전투를 한다.
        //전투를 하려면? 플레이어와 몬스터
        //전투? 플레이어가 몬스터를 공격하고 몬스터도 플레이어를 공격한다.
        //전투언제 끝나는가? 한쪽이 죽으면 끝난다.
        static void BattleMain()
        {
            Player player = new Player("Player",100,10);
            Player monster = new Player("Monster",20,10);

            while (true)
            {
                if (player.Death() == false)
                {
                    player.Attack(monster);
                    monster.Show();
                }
                else
                {
                    break;
                }

                if (monster.Death() == false)
                {
                    monster.Attack(player);
                    player.Show();
                }
                else
                {
                    break;
                }
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("khg");
            Console.WriteLine("Unity21");
            Console.WriteLine("Add:" + Add(10, 20));
            //MonsterAttackMain();
            //MonsterCriticalAttackMain();
            //StageMain();
            //MonsterAttackWhileMain();
            //MonsterListMain();
            BattleMain();
        }

        static void ValMain()
        {
            int nScore = 0;
            float fRat = 1.0f / 4.0f;
            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
        }
        //몬스터를 공격했다.
        //플레이어가 몬스터를 (공격:공격력만큼 체력이 감소)했다.
        //플레이어의 공격력만큼 플레이어의 체력이 감소했다. ->? 자해/자학
        //(플레이어의 공격력)만큼 (몬스터의 체력)이 감소했다. -> 공격
        //모든 변수를 출력해야 정상적인 결과인지 아닌지 알수있다.
        static void MonsterAttackMain()
        {
            int nPlayerAttack = 1;
            int nMonsterHP = 10;

            nMonsterHP = nMonsterHP - nPlayerAttack;

            Console.WriteLine("PlayerAttack:" + nPlayerAttack);
            Console.WriteLine("MonsterHP:" + nMonsterHP);
        }

        //플레이어가 몬스터를 공격하는데
        //(일정확률:상자안에 공을 준비하고 그공중에 한개를 꺼낼때 내가 꺼낸 공이 어떤것인지 예측되는 수치)로
        //(크리티컬:치명상을 입히는 공격 - 원래공격력에 150%를 준다.)이 발생한다.
        static void MonsterCriticalAttackMain()
        {
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            Random cRandom = new Random();
            int nRandom = cRandom.Next(1, 3);//1~2
            Console.WriteLine("Random:" + nRandom);
            if (nRandom == 1)
            {
                int nCritcalAttack = (int)((float)nPlayerAttack * 1.5f);
                nMonsterHP = nMonsterHP - nCritcalAttack;
                Console.WriteLine("Critcal Attack!"+ nCritcalAttack);
            }
            else if(nRandom == 2)
            {
                Console.WriteLine("Miss!");
            }
            else
                nMonsterHP = nMonsterHP - nPlayerAttack;

            Console.WriteLine("PlayerAttack:" + nPlayerAttack);
            Console.WriteLine("MonsterHP:" + nMonsterHP);
        }

        //마을,필드,상점을 입력하면 해당위치로 이동한다.
        //(텍스트로 이동장소를 입력)받아서 해당위치의 장소가 존재한다면, ~입니다. 라고 (출력)하라.
        static void StageMain()
        {
            string strInput = "";
            while (strInput != "나가기")
            {
                Console.Write("장소를 입력하세요!(마을,필드,상점,나가기):");
                strInput = Console.ReadLine();

                //Console.WriteLine(strInput+" 입니다!"); //다른값이 들어와도 이동한것으로취급된다.

                switch (strInput)
                {
                    case "마을":
                        Console.WriteLine("마을 입니다!");
                        break;
                    case "필드":
                        Console.WriteLine("필드 입니다!");
                        break;
                    case "상점":
                        Console.WriteLine("상점 입니다!");
                        break;
                    default:
                        Console.WriteLine("?!?!?!?!?!!?");
                        break;
                }
            }
            /*
            if(strInput == "마을")
            {
                Console.WriteLine("마을 입니다!");
            }
            else if (strInput == "필드")
            {
                Console.WriteLine("마을 입니다!");
            }
            else if (strInput == "상점")
            {
                Console.WriteLine("마을 입니다!");
            }
            else
            {
                Console.WriteLine("?!?!?!?!?!!?");
            }
            */
        }
        
        //플레이어가 몬스터를 죽을때까지 반복한다.
        //죽을때: 몬스터의 hp가 0이 될때 -> hp == 0 
        //살아아있을때: 몬스터의 hp가 0보다 클때
        static void MonsterAttackWhileMain()
        {
            int nPlayerAttack = 1; //1
            int nMonsterHP = 10; //10

            //while (nMonsterHP > 0) //1 == 0 -> T
            while(true)
            {
                if (nMonsterHP <= 0) break;
                nMonsterHP = nMonsterHP - nPlayerAttack;

                Console.WriteLine("PlayerAttack:" + nPlayerAttack);
                Console.WriteLine("MonsterHP:" + nMonsterHP);
            }
        }
        //몬스터를 리스트에 저장한다. 슬라임, 스켈레톤, 좀비, 드래곤
        static void MonsterListMain()
        {
            List<string> listMonsters = new List<string>();

            listMonsters.Add("Slime");
            listMonsters.Add("Skeleton");
            listMonsters.Add("Zombie");
            listMonsters.Add("Dragon");

            Console.WriteLine("0:"+listMonsters[0]);
            Console.WriteLine("3:"+listMonsters[3]);

            for(int i = 0; i < listMonsters.Count; i++)
            {
                Console.WriteLine(i+":" + listMonsters[i]);
            }
        }

        static int Add(int a, int b)
        {
            int c = a + b;
            return c;
        }
    }
}
