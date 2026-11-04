/* FUN_8016454c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016454c  body 0x8016454c..0x80164697  size 332 B
 * body sha256 d937a5562c70aebc337b849fbfb46529a0c788058881f003574c62de9f55b0ca
 * provider record sha256 c08c9afb021df6fa765a551d0b5c440cb8c26acafec9b5bd0f63eccb4102b2f4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016454c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
    sVar3 = *(short *)((int)param_1 + 0x212) + 4;
    *(short *)((int)param_1 + 0x212) = sVar3;
    if (sVar3 < 0x1101) goto LAB_80164674;
    *(undefined1 *)((int)param_1 + 6) = 2;
    uVar2 = 0x1100;
  }
  else if (bVar1 < 2) {
    if (bVar1 != 0) goto LAB_80164674;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *param_1 = *param_1 | 0x804;
    param_1[0x7a] = ((uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 0xc) * 0x1000000 + 0x760000;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined1 *)((int)param_1 + 0x2c1) = 9;
    *(undefined1 *)((int)param_1 + 0x2c3) = 3;
    *(undefined2 *)((int)param_1 + 0x2ba) = 0x60;
    uVar2 = 0x1000;
    *(undefined1 *)(param_1 + 0xae) = 1;
    *(undefined1 *)((int)param_1 + 0x2d9) = 1;
  }
  else {
    if (bVar1 != 2) goto LAB_80164674;
    sVar3 = *(short *)((int)param_1 + 0x212) + -4;
    *(short *)((int)param_1 + 0x212) = sVar3;
    uVar2 = 0x1000;
    if (0x1000 < sVar3) goto LAB_80164674;
    *(undefined1 *)((int)param_1 + 6) = 1;
  }
  *(undefined2 *)((int)param_1 + 0x212) = uVar2;
LAB_80164674:
  *(undefined1 *)((int)param_1 + 0x2d6) = 1;
  *(undefined1 *)((int)param_1 + 0x2d7) = 1;
  FUN_80162678(param_1);
  return;
}
