/* FUN_80166c7c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166c7c  body 0x80166c7c..0x80166d1b  size 160 B
 * body sha256 d78588ac8ad04a6ba1580978dc1749a89654f7d3d8e92761d51f24e1ec14a6a4
 * provider record sha256 3fb04d19c263dca9ebf2b855d32285b91ab498bdeb5bdf02338de074bdfe4ea7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166c7c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(uint *)(param_1 + 0x28c) < 0x9c4) {
    iVar1 = func_0x80032e74(*(undefined4 *)(param_1 + 0x2c4),*(undefined4 *)(param_1 + 0x28),
                            *(undefined4 *)(param_1 + 0x30),0x140);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 4) = 0x1130000;
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 1;
      return;
    }
    uVar2 = func_0x80033604();
    uVar3 = 0x10c0000;
    if ((uVar2 & 1) == 0) {
      uVar3 = 0x10f0000;
    }
  }
  else {
    iVar1 = func_0x80032e74(*(undefined4 *)(param_1 + 0x2c4),*(undefined4 *)(param_1 + 0x28),
                            *(undefined4 *)(param_1 + 0x30),0x1e0);
    uVar3 = 0x10c0000;
    if (iVar1 == 0) {
      uVar3 = 0x1140000;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar3;
  return;
}
