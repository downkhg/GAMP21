using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BillBaordEffect : MonoBehaviour
{
    public Renderer m_renderer;
    public Camera m_cCamera;

    // Start is called before the first frame update
    void Start()
    {
        m_renderer = GetComponent<Renderer>();
    }

    // Update is called once per frame
    void Update()
    {
        EffectAniUpdate();
        BillBoardUpdate();
    }

    void EffectAniUpdate()
    {
        Vector2 vTexOffset = m_renderer.material.mainTextureOffset;
    }

    void BillBoardUpdate()
    {
        transform.LookAt(m_cCamera.transform);
    }
}
