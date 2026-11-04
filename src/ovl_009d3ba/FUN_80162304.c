/* FUN_80162304
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162304  body 0x80162304..0x80162437  size 308 B
 * body sha256 2f411a0f0c03fa464d58ba32e745ce125d39dee6fda2b26c6f4cc93ca59d7f12
 * provider record sha256 14be3366e862fe6f3d2e0267c7b3de9238ea099820ed9e73059062b5ec4ef0d9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162304(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar3;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2b8);
        *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 700);
        return;
      }
      if (*(byte *)(param_1 + 0x1e9) < 0xb) {
        *(undefined2 *)(param_1 + 0x1e0) = 0x32;
        *(undefined2 *)(param_1 + 0x1e4) = 0;
        *(undefined2 *)(param_1 + 0x1e2) = 0;
        func_0x80032b5c(param_1,0);
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 400;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(param_1 + 0x2b4);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2b8);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 700);
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80032b5c(param_1,0x800);
  }
  sVar3 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar3;
  if (sVar3 == -1) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  return;
}
