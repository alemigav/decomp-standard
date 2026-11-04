/* FUN_801666c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801666c8  body 0x801666c8..0x801667af  size 232 B
 * body sha256 d15e775595a8b33da0ccd6e065e02664005784a7149b8d2e1a4a9f40829199ab
 * provider record sha256 65177f08d9b943a94c5415c4aac0daf549de8eaf9249aa54f31dadf13973947e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801666c8(uint *param_1)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  if (*(char *)((int)param_1 + 5) == '\0') {
    iVar2 = func_0x80089d54();
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_1 + 5) = 1;
      bVar3 = func_0x80033604();
      *(byte *)((int)param_1 + 0x206) = (bVar3 & 0x1f) + 0x1e;
    }
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x206);
    *(char *)((int)param_1 + 0x206) = cVar1 + -1;
    if (cVar1 == '\x01') {
      param_1[0x7a] = 0xd000700;
      *(undefined1 *)((int)param_1 + 5) = 0;
    }
  }
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined1 *)((int)param_1 + 0x2c1) = 2;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  }
  if (*(char *)((int)param_1 + 0x2d6) < '\0') {
    FUN_801668b4(param_1);
  }
  uVar4 = *param_1;
  *param_1 = uVar4 | 0x4000000;
  if ((int)param_1[0xb] < _DAT_800e115c) {
    *param_1 = uVar4 | 0xc000000;
  }
  return;
}
