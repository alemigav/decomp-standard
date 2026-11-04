/* FUN_800a64c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a64c8  body 0x800a64c8..0x800a681f  size 856 B
 * body sha256 a2d964bcebd4be5c7719f27ce558bf3a6b9a922cf93488e627656f2a54ab0a62
 * provider record sha256 6aa8e0ea1becced0c4f256a72a07ff0ba66cf7503bcaa2637a1d35d4e3810c23
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800a64c8(uint param_1,undefined2 param_2,uint param_3,uint param_4,byte param_5,char param_6
                ,undefined1 param_7,undefined2 param_8,undefined2 param_9,undefined1 param_10)

{
  ushort *puVar1;
  uint uVar2;
  char cVar4;
  int iVar3;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_s2;
  int iVar9;
  int iVar10;
  ushort local_48;
  undefined2 local_46;
  byte local_39;
  byte local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined1 local_32;
  uint local_30;
  
  iVar10 = -1;
  local_38 = param_5;
  local_36 = param_8;
  local_34 = param_9;
  local_32 = param_10;
  local_46 = param_2;
  puVar1 = (ushort *)FUN_800adfb4(param_1 >> 0x10,&local_48);
  local_39 = (byte)param_3;
  if ((puVar1 != (ushort *)0x0) && (iVar9 = 0, local_48 != 0)) {
    param_3 = param_3 & 0x7f;
    local_30 = param_4 & 0xff;
    do {
      if (((*puVar1 != 0xffff) && (*(byte *)(puVar1 + 1) <= param_3)) &&
         (param_3 <= *(byte *)((int)puVar1 + 3))) {
        uVar8 = param_3 + (int)*(char *)(puVar1 + 2);
        uVar2 = 0x7f;
        if (((int)uVar8 < 0x80) && (uVar2 = uVar8, (int)uVar8 < 0)) {
          uVar2 = 0;
        }
        if (param_6 != -1) {
          cVar4 = FUN_800ac77c(param_6,param_7);
          if ((cVar4 != '\0') && (iVar3 = FUN_800a62c0(uVar2 & 0x7f,param_6,param_7), iVar3 != -1))
          {
            return iVar3;
          }
        }
        uVar8 = 0x80;
        if ((puVar1[4] & 0x8000) == 0) {
          uVar7 = (*(byte *)(puVar1 + 4) - 0x40) + (uint)local_38;
          if ((int)uVar7 < 0) {
            uVar8 = 0;
          }
          else {
            uVar8 = 0x7f;
            if ((int)uVar7 < 0x80) {
              uVar8 = uVar7;
            }
          }
        }
        iVar5 = (param_1 >> 8 & 0xff) + (int)(short)puVar1[3];
        uVar7 = (uint)((ulonglong)
                       ((longlong)(int)(local_30 * *(byte *)((int)puVar1 + 5)) * 0x81020409) >> 0x26
                      );
        iVar3 = 0xff;
        if ((iVar5 < 0x100) && (iVar3 = iVar5, iVar5 < 0)) {
          iVar3 = 0;
        }
        uVar6 = param_1 & 0xff | iVar3 << 8 | (uint)*puVar1 << 0x10;
        if ((*puVar1 & 0xc000) == 0) {
          if (iVar10 == -1) {
            unaff_s2 = FUN_800b185c(uVar6,local_46,uVar2 & 0xff | local_39 & 0x80,uVar7 & 0xff,
                                    uVar8 & 0xff,param_6,param_7,local_36,local_34,0,local_32);
            if (unaff_s2 != 0xffffffff) {
              iVar10 = FUN_800ae300(&DAT_80144448 + (unaff_s2 & 0xff) * 0x1a0);
            }
          }
          else {
            uVar2 = FUN_800b185c(uVar6,local_46,uVar2 & 0xff | local_39 & 0x80,uVar7 & 0xff,
                                 uVar8 & 0xff,param_6,param_7,local_36,local_34,0,local_32);
            if (uVar2 != 0xffffffff) {
              *(uint *)((unaff_s2 & 0xff) * 0x1a0 + -0x7febbba8) = uVar2;
              *(uint *)((uVar2 & 0xff) * 0x1a0 + -0x7febbba4) = unaff_s2;
              unaff_s2 = uVar2;
            }
          }
        }
      }
      iVar9 = iVar9 + 1;
      puVar1 = puVar1 + 6;
    } while (iVar9 < (int)(uint)local_48);
  }
  return iVar10;
}
