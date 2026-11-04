/* FUN_80162b88
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162b88  body 0x80162b88..0x80162c1b  size 148 B
 * body sha256 2cb1aa5154dcb3b70b55e506cdba6943a9d05a55a135d3c6fe732be517a885ac
 * provider record sha256 3e8dadd38956e988cf2315b57780c4eaa8fafefabf3b73af56c993378a3efc53
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80162b88(int param_1)

{
  undefined4 uVar1;
  short sVar2;
  ushort *puVar3;
  ushort uVar4;
  
  puVar3 = *(ushort **)(param_1 + 0x1b0);
  uVar1 = 1;
  if (puVar3 != (ushort *)0x0) {
    sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)(((uint)*puVar3 + (uint)(puVar3[2] >> 1)) * 0x10000) >> 0x10,
                            (int)(((uint)puVar3[1] + (uint)(puVar3[3] >> 1)) * 0x10000) >> 0x10);
    uVar4 = sVar2 - *(short *)(param_1 + 0x66) & 0xfff;
    if (0x800 < uVar4) {
      uVar4 = uVar4 | 0xf000;
    }
    uVar1 = 0xffffffff;
    if ((int)((uint)uVar4 << 0x10) < 1) {
      uVar1 = 1;
    }
  }
  return uVar1;
}
