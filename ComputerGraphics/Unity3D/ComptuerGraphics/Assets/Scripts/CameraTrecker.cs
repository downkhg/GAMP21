using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraTrecker : MonoBehaviour
{
    public GameObject m_objTarget;
    public float m_fDist;
    public Vector3 m_vAsix = Vector3.up;

    // Start is called before the first frame update
    void Start()
    {
        
    }
    float m_fAngle;
    // Update is called once per frame
    void Update()
    {
        Vector3 vDir = m_objTarget.transform.forward;
        Vector3 vPos = m_objTarget.transform.position;

        vDir = Quaternion.AngleAxis(m_fAngle, m_vAsix) * vDir;
        Vector3 vResult = vPos + vDir * m_fDist;

        this.transform.position = vResult;
        this.transform.LookAt(m_objTarget.transform);

        m_fAngle++;

        if (m_fAngle < 360)
            m_fAngle -= 360;
    }
}
