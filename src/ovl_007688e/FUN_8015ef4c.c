/* FUN_8015ef4c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015ef4c  body 0x8015ef4c..0x8015f297  size 844 B
 * body sha256 b62ebe8c71bac0060ba718eed400499d784b423fb7d394d941ef0ae72e263f87
 * provider record sha256 3a3519515394b308aaada10c4abace27792f45a7c28c53e365bb87a37ceb5fe5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015f118) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015ef4c(int param_1)

{
  int iVar1;
  char cVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  puVar3 = &DAT_80160c08;
  do {
    cVar2 = DAT_80160c27;
    iVar1 = (uint)*puVar3 * 0x28;
    (&DAT_80160c3a)[iVar1] = DAT_80160c27;
    (&DAT_80160c39)[iVar1] = cVar2;
    (&DAT_80160c38)[iVar1] = cVar2;
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 5);
  if (param_1 == 0) {
    *(undefined2 *)(&DAT_80160f62 + (uint)DAT_800dfbe8 * 0x14) = 0;
    *(undefined2 *)(&DAT_80160ec2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    *(undefined2 *)(&DAT_80160e22 + (uint)DAT_800dfbe8 * 0x14) = 0;
    *(undefined2 *)(&DAT_80160dd2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    uVar4 = DAT_800e9012 >> 2 & 3;
  }
  else {
    *(undefined2 *)(&DAT_80160f62 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_80160ec2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_80160e22 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_80160dd2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    uVar4 = 3;
  }
  uVar5 = 0;
  iVar1 = (uint)(ushort)(&DAT_80160c08)[uVar4 + 2] * 0x28;
  cVar2 = DAT_80160c27 + DAT_80160c23;
  (&DAT_80160c3a)[iVar1] = cVar2;
  (&DAT_80160c39)[iVar1] = cVar2;
  (&DAT_80160c38)[iVar1] = cVar2;
  do {
    _DAT_800df8b4 =
         func_0x80043988(_DAT_800df8b4,&DAT_80160c38 + (uint)(ushort)(&DAT_80160c08)[uVar5] * 0x28,0
                         ,0);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 2);
  _DAT_800df8b4 =
       func_0x80043988(_DAT_800df8b4,
                       &DAT_80160c38 +
                       (uint)(ushort)(&DAT_80160c08)[(DAT_800e9012 >> 2 & 3) + 2] * 0x28,0,0);
  return;
}
