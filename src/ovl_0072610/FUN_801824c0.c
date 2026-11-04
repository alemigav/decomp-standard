/* FUN_801824c0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801824c0  body 0x801824c0..0x801826bf  size 512 B
 * body sha256 92da4f8964774c730f9cd4969b000c1d29d651a8c84f4c44825b4526d567b027
 * provider record sha256 0b0a17dd439a6f149d34e3971729c98a17fd86734d2b6a8c66bdcc4e4ee08ae6
 * callees 16 direct (16 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801824c0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,int param_7,int param_8,uint param_9,uint param_10,int param_11)

{
  int iVar1;
  
  iVar1 = param_1 + param_3 * (param_8 + ((int)param_10 >> 1)) + param_7 + ((int)param_9 >> 1);
  param_7 = param_2 + param_3 * param_8 + param_7;
  if ((param_9 & 1) == 0) {
    if ((param_10 & 1) == 0) {
      if (param_11 == 0) {
        if (param_5 == 8) {
          FUN_8018277c(iVar1,param_7,param_4);
        }
        else {
          FUN_801826c0(iVar1,param_7,param_4);
        }
      }
      else if (param_5 == 8) {
        FUN_801829b4(iVar1,param_7,param_4);
      }
      else {
        FUN_801827f8(iVar1,param_7,param_4);
      }
    }
    else if (param_11 == 0) {
      if (param_5 == 8) {
        FUN_80183298(iVar1,param_7,param_3,param_4,param_6);
      }
      else {
        FUN_801830d0();
      }
    }
    else if (param_5 == 8) {
      FUN_80183668(iVar1,param_7,param_3,param_4,param_6);
    }
    else {
      FUN_801833a0();
    }
  }
  else if ((param_10 & 1) == 0) {
    if (param_11 == 0) {
      if (param_5 == 8) {
        FUN_80182c28(iVar1,param_7,param_4);
      }
      else {
        FUN_80182ab0(iVar1,param_7,param_4);
      }
    }
    else if (param_5 == 8) {
      FUN_80182f78(iVar1,param_7,param_4);
    }
    else {
      FUN_80182d00(iVar1,param_7,param_4);
    }
  }
  else if (param_11 == 0) {
    if (param_5 == 8) {
      FUN_80183a40(iVar1,param_7,param_3,param_4,param_6);
    }
    else {
      FUN_801837f0();
    }
  }
  else if (param_5 == 8) {
    FUN_80183ea4(iVar1,param_7,param_3,param_4,param_6);
  }
  else {
    FUN_80183b90();
  }
  return;
}
