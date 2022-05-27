using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public delegate void EffectFunc(GameObject obj);

public static class EffectFuncs
{
    public static void SuperMode(GameObject obj)
    {
        SuperMode superMode = obj.GetComponent<SuperMode>();
        superMode.OnMode();
    }
    public static void Recovery(GameObject obj)
    {
        Player player = obj.GetComponent<Player>();
        player.Recovery();
    }

    public static void Bullet(GameObject obj)
    {
       
        Dynamic dynamic = obj.GetComponent<Dynamic>();
        if (dynamic)
        {
            Gun gun = dynamic.gun;
            gun.eGunState = Gun.E_GUN_STATE.BULLET_GUN;
        }
    }

    public static void Laser(GameObject obj)
    {
        Dynamic dynamic = obj.GetComponent<Dynamic>();
        if (dynamic)
        {
            Gun gun = dynamic.gun;
            gun.eGunState = Gun.E_GUN_STATE.LASER_GUN;
        }
    }

    public static void Grenade(GameObject obj)
    {

    }
}

public class EffectDelegateManager : MonoBehaviour
{
    public enum EffectFucntion { SUPER_MODE, RECOVERY, BULLET, LASER, GRENADE, MAX }
    List<EffectFunc> listEffectFunction;

    public EffectFunc GetEffect(int idx)
    {
        return listEffectFunction[idx];
    }

    public EffectFunc GetEffect(EffectFucntion enffect)
    {
        return listEffectFunction[(int)enffect];
    }

    public void InitEffectFunction()
    {
        listEffectFunction = new List<EffectFunc>((int)EffectFucntion.MAX);
        listEffectFunction.Add(EffectFuncs.SuperMode);
        listEffectFunction.Add(EffectFuncs.Recovery);
        listEffectFunction.Add(EffectFuncs.Bullet);
        listEffectFunction.Add(EffectFuncs.Laser);
        listEffectFunction.Add(EffectFuncs.Grenade);
    }

    public void Release()
    {
        listEffectFunction.Clear();
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
