/* FUN_80083e60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083e60  body 0x80083e60..0x80083e7f  size 32 B
 * body sha256 e5e9fc82530fea7bd8079d2f1ce89e41fe71ed7187e8c76bd6b19f74e3047679
 * provider record sha256 da61a3d9fed93df729ba2e32cdedb6ea2439ad4e3a9097c39f19f5b886786576
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80083e60(float param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5,
                  float param_6)

{
  return (param_5 - param_1) * (param_5 - param_1) + (param_6 - param_2) * (param_6 - param_2);
}
