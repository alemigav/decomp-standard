/* FUN_8000a6c0
 * image   boot (boot), base 0x80000480
 * address 0x8000a6c0  body 0x8000a6c0..0x8000a8fb  size 572 B
 * body sha256 598491a311c6dc1ee0b5ec53aa92a52e1c492b5cd23f0c59488f26d4c0ad5ccd
 * provider record sha256 c96d5efc27542abe8c9218d1105969ffbd2ce90aeedc6251b8c960a87ca14108
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000a6c0(uint *param_1,int param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint unaff_s0;
  ushort uVar6;
  uint uVar7;
  ushort auStack_148 [128];
  int local_48;
  short local_44;
  undefined2 local_42;
  undefined1 local_3c [4];
  undefined1 local_38 [16];
  
  if (param_2 < (int)param_1[0x14] && -1 < param_2) {
    if ((*param_1 & 1) == 0) {
      return 5;
    }
    iVar2 = FUN_8000a2d0(param_1);
    if (iVar2 == 2) {
      return 2;
    }
    if (*(char *)((int)param_1 + 0x65) != '\0') {
      *(undefined1 *)((int)param_1 + 0x65) = 0;
      iVar2 = FUN_8000a66c(param_1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = FUN_800087a0(param_1[1],param_1[2],param_1[0x17] + param_2 & 0xffff,&local_48);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_44 == 0) {
      return 5;
    }
    if (local_48 != 0) {
      if ((int)(uint)local_42 < (int)param_1[0x18]) {
        return 3;
      }
      uVar6 = local_42 >> 8;
      uVar7 = (uint)(byte)local_42;
      iVar2 = 0;
      if (uVar6 < *(byte *)(param_1 + 0x19)) {
        do {
          iVar3 = FUN_8000a394(param_1,auStack_148,0);
          if (iVar3 != 0) {
            return iVar3;
          }
          unaff_s0 = (uint)auStack_148[uVar7 & 0xff];
          iVar2 = iVar2 + 1;
          do {
            if ((int)unaff_s0 < (int)param_1[0x18]) goto LAB_8000a844;
            uVar4 = unaff_s0 & 0xff;
            unaff_s0 = (uint)auStack_148[uVar4];
            uVar1 = auStack_148[uVar4] >> 8;
            iVar2 = iVar2 + 1;
          } while (uVar1 == uVar6);
          uVar7 = unaff_s0;
          uVar6 = uVar1;
LAB_8000a844:
          if (unaff_s0 == 1) goto LAB_8000a86c;
        } while (uVar6 < *(byte *)(param_1 + 0x19));
      }
      if ((unaff_s0 & 0xffff) != 1) {
        return 3;
      }
LAB_8000a86c:
      *param_3 = iVar2 << 8;
      *(short *)(param_3 + 2) = local_44;
      puVar5 = local_38;
      param_3[1] = local_48;
      iVar2 = 0;
      do {
        iVar3 = iVar2 + 1;
        *(undefined1 *)((int)param_3 + iVar2 + 0xe) = *puVar5;
        puVar5 = puVar5 + 1;
        iVar2 = iVar3;
      } while (iVar3 < 0x10);
      puVar5 = local_3c;
      iVar2 = 0;
      do {
        iVar3 = iVar2 + 1;
        *(undefined1 *)((int)param_3 + iVar2 + 10) = *puVar5;
        puVar5 = puVar5 + 1;
        iVar2 = iVar3;
      } while (iVar3 < 4);
      return 0;
    }
  }
  return 5;
}
