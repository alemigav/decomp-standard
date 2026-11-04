/* FUN_8000f050
 * image   boot (boot), base 0x80000480
 * address 0x8000f050  body 0x8000f050..0x8000f5bf  size 1392 B
 * body sha256 5dfb1019dc1b5b7c8f4af5f1f273e77dee39d0c3d011e1bc3467704d003baecf
 * provider record sha256 f4149a7885bb8908270f095ce820bff43bf14c800fa3791d851fd9ea03c7019b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000f050(code *param_1,int param_2,byte *param_3,int *param_4)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int *local_resc;
  undefined1 auStack_78 [8];
  int local_70;
  int local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  int local_4c;
  uint local_48;
  byte local_44;
  undefined1 auStack_40 [32];
  
  local_4c = 0;
  local_resc = param_4;
  while( true ) {
    bVar1 = *param_3;
    pbVar6 = param_3;
    while (bVar1 != 0 && bVar1 != 0x25) {
      pbVar6 = pbVar6 + 1;
      bVar1 = *pbVar6;
    }
    iVar4 = (int)pbVar6 - (int)param_3;
    if (0 < iVar4) {
      param_2 = (*param_1)(param_2,param_3,iVar4);
      if (param_2 == 0) {
        return local_4c;
      }
      local_4c = local_4c + iVar4;
    }
    if (bVar1 == 0) break;
    local_48 = 0;
    while( true ) {
      pbVar7 = pbVar6 + 1;
      iVar4 = FUN_8000de40(0x80011d10,*pbVar7);
      if (iVar4 == 0) break;
      local_48 = local_48 | *(uint *)((iVar4 + 0x7ffee2f0) * 4 + -0x7ffee2e8);
      pbVar6 = pbVar7;
    }
    uVar3 = (uint)*pbVar7;
    if (uVar3 == 0x2a) {
      piVar2 = (int *)((int)local_resc + 3U & 0xfffffffc);
      local_resc = piVar2 + 1;
      local_50 = *piVar2;
      if ((int)local_50 < 0) {
        local_50 = -local_50;
        local_48 = local_48 | 4;
      }
      pbVar7 = pbVar6 + 2;
    }
    else {
      local_50 = 0;
      while (uVar3 - 0x30 < 10) {
        if ((int)local_50 < 999) {
          local_50 = local_50 * 10 + (uint)*pbVar7 + -0x30;
        }
        pbVar7 = pbVar7 + 1;
        uVar3 = (uint)*pbVar7;
      }
    }
    if (*pbVar7 == 0x2e) {
      uVar3 = (uint)pbVar7[1];
      if (uVar3 == 0x2a) {
        piVar2 = (int *)((int)local_resc + 3U & 0xfffffffc);
        local_resc = piVar2 + 1;
        local_54 = *piVar2;
        pbVar7 = pbVar7 + 2;
      }
      else {
        local_54 = 0;
        pbVar7 = pbVar7 + 1;
        while (uVar3 - 0x30 < 10) {
          if (local_54 < 999) {
            local_54 = local_54 * 10 + (uint)*pbVar7 + -0x30;
          }
          pbVar7 = pbVar7 + 1;
          uVar3 = (uint)*pbVar7;
        }
      }
    }
    else {
      local_54 = -1;
    }
    bVar1 = *pbVar7;
    iVar4 = FUN_8000de40(0x80011d30,bVar1);
    if (iVar4 == 0) {
      local_44 = 0;
    }
    else {
      pbVar7 = pbVar7 + 1;
      local_44 = bVar1;
    }
    if ((local_44 == 0x6c) && (*pbVar7 == 0x6c)) {
      local_44 = 0x4c;
      pbVar7 = pbVar7 + 1;
    }
    FUN_8000f5c0(auStack_78,&local_resc,*pbVar7,auStack_40);
    uVar3 = local_50 - (local_6c + local_68 + local_64 + local_60 + local_5c + local_58);
    local_50 = uVar3;
    if (((local_48 & 4) == 0) && (0 < (int)uVar3)) {
      do {
        uVar5 = 0x20;
        if (uVar3 < 0x21) {
          uVar5 = uVar3;
        }
        if (0 < (int)uVar5) {
          param_2 = (*param_1)(param_2,0x80013810,uVar5);
          if (param_2 == 0) {
            return local_4c;
          }
          local_4c = local_4c + uVar5;
        }
        uVar3 = uVar3 - uVar5;
      } while (0 < (int)uVar3);
    }
    if (0 < local_6c) {
      param_2 = (*param_1)(param_2,auStack_40);
      if (param_2 == 0) {
        return local_4c;
      }
      local_4c = local_4c + local_6c;
    }
    if (0 < (int)local_68) {
      uVar3 = local_68;
      do {
        uVar5 = 0x20;
        if (uVar3 < 0x21) {
          uVar5 = uVar3;
        }
        if (0 < (int)uVar5) {
          param_2 = (*param_1)(param_2,0x80013834,uVar5);
          if (param_2 == 0) {
            return local_4c;
          }
          local_4c = local_4c + uVar5;
        }
        uVar3 = uVar3 - uVar5;
      } while (0 < (int)uVar3);
    }
    if (0 < local_64) {
      param_2 = (*param_1)(param_2,local_70);
      if (param_2 == 0) {
        return local_4c;
      }
      local_4c = local_4c + local_64;
    }
    if (0 < (int)local_60) {
      uVar3 = local_60;
      do {
        uVar5 = 0x20;
        if (uVar3 < 0x21) {
          uVar5 = uVar3;
        }
        if (0 < (int)uVar5) {
          param_2 = (*param_1)(param_2,0x80013834,uVar5);
          if (param_2 == 0) {
            return local_4c;
          }
          local_4c = local_4c + uVar5;
        }
        uVar3 = uVar3 - uVar5;
      } while (0 < (int)uVar3);
    }
    if (0 < local_5c) {
      param_2 = (*param_1)(param_2,local_70 + local_64);
      if (param_2 == 0) {
        return local_4c;
      }
      local_4c = local_4c + local_5c;
    }
    if (0 < (int)local_58) {
      uVar3 = local_58;
      do {
        uVar5 = 0x20;
        if (uVar3 < 0x21) {
          uVar5 = uVar3;
        }
        if (0 < (int)uVar5) {
          param_2 = (*param_1)(param_2,0x80013834,uVar5);
          if (param_2 == 0) {
            return local_4c;
          }
          local_4c = local_4c + uVar5;
        }
        uVar3 = uVar3 - uVar5;
      } while (0 < (int)uVar3);
    }
    param_3 = pbVar7 + 1;
    if (((local_48 & 4) != 0) && (uVar3 = local_50, 0 < (int)local_50)) {
      do {
        uVar5 = 0x20;
        if (uVar3 < 0x21) {
          uVar5 = uVar3;
        }
        if (0 < (int)uVar5) {
          param_2 = (*param_1)(param_2,0x80013810,uVar5);
          if (param_2 == 0) {
            return local_4c;
          }
          local_4c = local_4c + uVar5;
        }
        uVar3 = uVar3 - uVar5;
      } while (0 < (int)uVar3);
      param_3 = pbVar7 + 1;
    }
  }
  return local_4c;
}
