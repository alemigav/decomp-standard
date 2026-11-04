/* func_80161cf0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161e27  size 312 B
 * body sha256 5ef804d55034d2115bcea93c873d41c4f5224d78f6f1bc2327274000be67123f
 * provider record sha256 47c4031438915426ef6ebe427380916d779793ea5f35681440d6052a5e5b1787
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  ushort uVar2;
  int iVar1;
  char cVar3;
  int in_a0;
  uint *puVar4;
  ushort *puVar5;
  uint uVar6;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  uVar6 = 0;
  _DAT_800df920 = 0x2de4;
  puVar5 = &DAT_801662e0;
  do {
    puVar4 = (uint *)(*(int *)(in_a0 + 0x234) + (uint)*puVar5 * 0x178);
    *puVar4 = *puVar4 | 0x40;
    uVar2 = func_0x80033604();
    puVar5[1] = (uVar2 & 0xff) << 4;
    iVar1 = func_0x80033604();
    puVar5[2] = puVar5[2] +
                (short)((uint)(((iVar1 << 0x18) >> 0x18) - ((iVar1 << 0x18) >> 0x1f)) >> 1);
    cVar3 = func_0x80033604();
    puVar5[4] = puVar5[4] + (short)cVar3;
    iVar1 = func_0x80033604();
    puVar5[6] = (ushort)((iVar1 << 0x18) >> 0x17);
    puVar5[7] = 0;
    local_1c = 0;
    local_1e = 0;
    local_20 = 0;
    func_0x800838c0(puVar4 + 7,puVar4 + 0x16,puVar4 + 0xe,&local_20);
    uVar2 = *(ushort *)(puVar4 + 0x17);
    uVar6 = uVar6 + 1;
    *(short *)(puVar4 + 0x17) = (short)(uVar2 & 0xfff);
    puVar5[8] = (ushort)((uVar2 & 0xfff) - 0x400 < 0x800);
    puVar5[5] = 0;
    puVar5 = puVar5 + 10;
  } while (uVar6 < 0xf);
  return;
}
