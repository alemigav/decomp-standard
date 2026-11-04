/* FUN_8000b7c0
 * image   boot (boot), base 0x80000480
 * address 0x8000b7c0  body 0x8000b7c0..0x8000bbef  size 1072 B
 * body sha256 b1fd102793238422fdc29ce08c787426a8d1b7f171a9cfc17be49277817c2d44
 * provider record sha256 0952b359569eb9b4a1f5027a7f8c9268a97326d006387acc543252823115c7b8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000b7c0(uint *param_1,int param_2,char param_3,uint param_4,uint param_5,int param_6)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_148;
  short local_144;
  undefined2 local_142;
  byte local_140;
  ushort auStack_128 [128];
  char local_28;
  undefined2 local_26;
  
  if ((param_2 < (int)param_1[0x14] && -1 < param_2) && (0 < (int)param_5)) {
    if ((param_5 & 0x1f) != 0) {
      return 5;
    }
    if (-1 < (int)param_4) {
      if ((param_4 & 0x1f) != 0) {
        return 5;
      }
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
      iVar2 = FUN_800087a0(param_1[1],param_1[2],param_1[0x17] + param_2 & 0xffff,&local_148);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_144 == 0) {
        return 5;
      }
      if (local_148 == 0) {
        return 5;
      }
      if ((((int)param_1[0x18] <= (int)(uint)local_142) &&
          (local_142._0_1_ < *(byte *)(param_1 + 0x19))) && ('\0' < (char)local_142)) {
        if ((param_3 == '\0') && ((local_140 & 2) == 0)) {
          return 6;
        }
        local_28 = -1;
        if ((int)param_4 < 0) {
          param_4 = param_4 + 0x1f;
        }
        iVar2 = (int)param_4 >> 5;
        local_26 = local_142;
        if (7 < iVar2) {
          do {
            if (local_26._0_1_ == local_28) {
LAB_8000b990:
              uVar1 = auStack_128[(byte)local_26];
              local_26 = uVar1;
              if ((((int)(uint)uVar1 < (int)param_1[0x18]) ||
                  (local_26._0_1_ = (byte)(uVar1 >> 8), *(byte *)(param_1 + 0x19) <= local_26._0_1_)
                  ) || (local_26._1_1_ = (byte)uVar1, (char)(byte)local_26 < '\x01')) {
                iVar3 = 3;
                if (uVar1 == 1) {
                  iVar3 = 5;
                }
              }
              else {
                iVar3 = 0;
              }
            }
            else {
              local_28 = local_26._0_1_;
              iVar3 = FUN_8000a394(param_1,auStack_128,0);
              if (iVar3 == 0) goto LAB_8000b990;
            }
            iVar2 = iVar2 + -8;
            if (iVar3 != 0) {
              return iVar3;
            }
          } while (7 < iVar2);
        }
        if ((int)param_5 < 0) {
          param_5 = param_5 + 0x1f;
        }
        iVar3 = (int)param_5 >> 5;
        uVar1 = local_26;
        do {
          local_26 = uVar1;
          if (iVar3 < 1) {
            if (param_3 != '\x01') {
              return 0;
            }
            if ((local_140 & 2) != 0) {
              return 0;
            }
            local_140 = local_140 | 2;
            *(undefined1 *)((int)param_1 + 0x65) = 0;
            iVar2 = FUN_8000a66c(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = FUN_80008b70(param_1[1],param_1[2],param_1[0x17] + param_2 & 0xffff,&local_148,0
                                );
            if (iVar2 == 0) {
              return 0;
            }
            return iVar2;
          }
          if (iVar2 == 8) {
            local_26._0_1_ = (byte)(uVar1 >> 8);
            if (local_26._0_1_ == local_28) {
LAB_8000ba60:
              local_26 = uVar1;
              uVar1 = auStack_128[(byte)local_26];
              local_26 = uVar1;
              if ((((int)(uint)uVar1 < (int)param_1[0x18]) ||
                  (local_26._0_1_ = (byte)(uVar1 >> 8), *(byte *)(param_1 + 0x19) <= local_26._0_1_)
                  ) || (local_26._1_1_ = (byte)uVar1, (char)(byte)local_26 < '\x01')) {
                iVar4 = 3;
                if (uVar1 == 1) {
                  iVar4 = 5;
                }
              }
              else {
                iVar4 = 0;
              }
            }
            else {
              local_28 = local_26._0_1_;
              iVar4 = FUN_8000a394(param_1,auStack_128,0);
              uVar1 = local_26;
              if (iVar4 == 0) goto LAB_8000ba60;
            }
            iVar2 = 0;
            if (iVar4 != 0) {
              return iVar4;
            }
          }
          if (*(char *)((int)param_1 + 0x65) != local_26._0_1_) {
            *(byte *)((int)param_1 + 0x65) = local_26._0_1_;
            iVar4 = FUN_8000a66c(param_1);
            if (iVar4 != 0) {
              return iVar4;
            }
          }
          uVar5 = (uint)(byte)local_26 * 8 + iVar2;
          if (param_3 == '\0') {
            iVar4 = FUN_800087a0(param_1[1],param_1[2],uVar5 & 0xffff,param_6);
          }
          else {
            iVar4 = FUN_80008b70(param_1[1],param_1[2],uVar5 & 0xffff,param_6,0);
          }
          param_6 = param_6 + 0x20;
          if (iVar4 != 0) {
            return iVar4;
          }
          iVar3 = iVar3 + -1;
          iVar2 = iVar2 + 1;
          uVar1 = local_26;
        } while( true );
      }
      if (local_142 != 1) {
        return 3;
      }
    }
  }
  return 5;
}
