/* FUN_801625e0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801625e0  body 0x801625e0..0x80162783  size 420 B
 * body sha256 a3a20eb8f76e9cd2f6ed839c7a1722864c922c9d103ff7624ecc8415032f8c10
 * provider record sha256 a11ec95acb20214ffbe99ce295338404877d2017910efbbc759dd5d8fa1704e8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801625e0(int param_1)

{
  short sVar2;
  char cVar4;
  uint uVar1;
  short sVar3;
  int iVar5;
  undefined1 *puVar6;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar6 = &DAT_800e1130;
  }
  else {
    puVar6 = _DAT_800e13ec;
  }
  if ((*(char *)(param_1 + 0x207) == '\0') && (*(char *)(param_1 + 0x2c7) != '\0')) {
    sVar2 = func_0x80032e74(param_1,*(undefined4 *)(puVar6 + 0x28),*(undefined4 *)(puVar6 + 0x30),4)
    ;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar2;
    cVar4 = FUN_80166074(param_1);
    *(char *)(param_1 + 0x207) = cVar4;
    if (cVar4 != '\0') {
      sVar2 = *(short *)(param_1 + 0x66);
      uVar1 = func_0x80033604(param_1);
      sVar3 = sVar2 + 0x80;
      if ((uVar1 & 1) == 0) {
        sVar3 = sVar2 + -0x80;
      }
      *(short *)(param_1 + 0x66) = sVar3;
    }
  }
  *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + *(short *)(param_1 + 500);
  func_0x80032bd8(param_1,0,0);
  if ((*(short *)(param_1 + 0x1e2) < 0) ||
     (*(int *)(param_1 + 0x2c) + 0x30f < (int)*(short *)(param_1 + 0x25e))) {
    iVar5 = (int)*(short *)(param_1 + 0x1e2);
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    if (iVar5 < (int)*(short *)(param_1 + 500) << 1) {
      if ((*(char *)(param_1 + 0x2c4) != '\0') && ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
        *(undefined1 *)(param_1 + 5) = 7;
        *(undefined2 *)(param_1 + 6) = 0;
      }
      if ((*(char *)(param_1 + 0x2c6) != '\0') &&
         (iVar5 = FUN_80165fb4(param_1,0,0x73a,0x180), iVar5 != 0)) {
        *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        puVar6[0x26f] = puVar6[0x26f] | 0x80;
        *(undefined1 *)(param_1 + 5) = 3;
        *(undefined2 *)(param_1 + 6) = 0;
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  return;
}
