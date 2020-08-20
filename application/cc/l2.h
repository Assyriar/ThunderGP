#ifndef __L2_H__
#define __L2_H__


#define MAX_PROP                  (INT_MAX - 1)

#define VERTEX_ACTIVE_BIT_MASK    (0x80000000)
#define IS_ACTIVE_VERTEX(a)       (a != 0)

/* source vertex property process */
inline prop_t preprocessProperty(prop_t srcProp)
{
    return ((srcProp));
}

/* source vertex property & edge property */
inline prop_t updateCalculation(prop_t srcProp, prop_t edgeProp)
{
    return (srcProp);
}

/* destination property update in RAW solver */
inline prop_t updateMergeInRAWSolver(prop_t ori, prop_t update)
{
    return (ori | update);
}

/* destination property update dst buffer update */
inline prop_t updateDestination(prop_t ori, prop_t update)
{
    return (ori | update);
}

inline prop_t applyCalculation( prop_t tProp,
                                prop_t source,
                                prop_t outDeg,
                                unsigned int (&extra)[APPLY_REF_ARRAY_SIZE],
                                unsigned int arg
                              )
{

    for (int i = 0; i < APPLY_REF_ARRAY_SIZE; i++)
    {
        const prop_t mask = (1<<i);
        if ((source&mask) != (tProp & mask))
        {
            extra[i] = 1;
        }
    }

    return tProp | source;
}

#endif /* __L2_H__ */
