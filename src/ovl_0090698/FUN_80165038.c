/* FUN_80165038
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165038  body 0x80165038..0x80165177  size 320 B
 * body sha256 f5d3f2b4a8b90c4fac2b7dd71bbc22f31987c56b07abfe940d628a23f29cc388
 * provider record sha256 590311f3782d21f502ed3f479f2f8574d490ec0181adda79e55ef0b2cd8be267
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165038(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_80166cbc(param_1,(int)*(short *)(param_1 + 0x7d),(int)*(short *)((int)param_1 + 0x1f6),0);
  *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + 0x28;
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)(param_1[0xb] + 400)) {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *(undefined2 *)(param_1 + 0x19) = 0;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(undefined1 *)((int)param_1 + 6) = 2;
    param_1[0x7a] = 0x9000300;
    *param_1 = *param_1 & 0xefffffff | 0xc000000;
    *(ushort *)((int)param_1 + 0x66) =
         -(*(short *)((int)param_1 + 0x2c2) +
          (ushort)*(byte *)(param_1 + 0xb3) * 0x400 * (*(byte *)(param_1 + 0xb3) & 1));
    func_0x80089d54(param_1,param_2,param_3,0x400);
    param_1[0x48] = 0;
    param_1[0x49] = 0;
    param_1[0x4a] = 0;
    param_1[0x4b] = 0x3200320;
    param_1[0x4c] = 0;
    param_1[0x4d] = 0xfa8803e8;
    param_1[0x4e] = 0x3e80578;
    param_1[0x4f] = 0;
    uVar1 = 5;
    *(undefined1 *)((int)param_1 + 0x2c1) = 0;
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      uVar1 = 6;
    }
    func_0x80077d18(uVar1,param_1);
  }
  return;
}
