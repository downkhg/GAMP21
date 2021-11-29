using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//플레이어가 죽으면 살린다.
//플레이어가 죽었다?
public class Responner : MonoBehaviour
{
    public GameObject prefabPlayer;
    public GameObject objPlayer = null;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(objPlayer == null)
        {
            objPlayer = Instantiate(prefabPlayer);
        }
    }
}
