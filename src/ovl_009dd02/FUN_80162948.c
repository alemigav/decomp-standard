/* FUN_80162948
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162948  body 0x80162948..0x80162a6b  size 292 B
 * body sha256 7dfcabaac25435a02b2771913d806d5105b8e9453939ae8c8f90c3c3599954bf
 * provider record sha256 e2c2c718bd369e61e3bac01f78ce314e7599a82c0a4c78fa4403687e50b76667
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162948(int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar2 = &DAT_800e1130;
  }
  else {
    puVar2 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar3 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  func_0x80033648(param_1);
  *(ushort *)(param_1 + 0x66) =
       *(short *)(param_1 + 0x66) + 0x800 + (ushort)*(byte *)(param_1 + 0x2cd) * 0x800;
  sVar1 = func_0x80032e74(param_1,*(undefined4 *)(puVar2 + 0x28),*(undefined4 *)(puVar2 + 0x30),
                          0x200);
  *(ushort *)(param_1 + 0x66) =
       *(short *)(param_1 + 0x66) + -0x800 + (ushort)*(byte *)(param_1 + 0x2cd) * -0x800;
  if ((((int)uVar3 < 3000) && (sVar1 == 0)) && (*(char *)(param_1 + 0x2ce) == '\0')) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  if (*(short *)(puVar2 + 0x1f2) < 0) {
    *(undefined1 *)(param_1 + 5) = 0;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_80162a6c(param_1);
  FUN_80166a04(param_1);
  FUN_80162678(param_1);
  return;
}
