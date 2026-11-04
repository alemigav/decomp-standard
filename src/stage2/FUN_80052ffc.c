/* FUN_80052ffc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052ffc  body 0x80052ffc..0x8005325f  size 612 B
 * body sha256 c5b3ae47922d6169cf3db01365fa50af2b985e70f576810af1ccff3ebcf760b0
 * provider record sha256 6154bc5f9ec3489b6d2eabcabfa30949eeb081acaa51dc3b97b86069d1965a13
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80052ffc(uint param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  char cVar4;
  undefined4 uVar3;
  undefined1 uVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 local_18 [2];
  
  pcVar1 = DAT_8010d940;
  local_18[0] = 0;
  iVar2 = FUN_800532b4();
  if (iVar2 == 0) {
LAB_80053244:
    uVar3 = 0;
  }
  else {
    cVar4 = pcVar1[0x2d9];
    pcVar1[0x2de] = '\x01';
    if (cVar4 == '\x01') {
      pcVar1[0x2d8] = '\0';
    }
    else if (param_1 == 0) {
      if (param_2 == 1) {
        pcVar1[(byte)pcVar1[0x2d8] + 0x2e4] = cVar4;
        cVar4 = pcVar1[0x2d9];
        if (cVar4 == '\x02') {
          pcVar1[0x2d8] = '\x01';
          FUN_80053c4c(0x41);
        }
        else if (cVar4 == '\x03') {
          pcVar1[0x2d8] = '\x01';
          FUN_80053c4c(0x42);
        }
        else if (cVar4 == '\x04') {
          pcVar1[0x2d8] = '\x01';
          FUN_80053c4c(0x43);
        }
        else {
          if (cVar4 != '\x05') {
            return 0;
          }
          pcVar1[0x2d8] = '\x01';
          FUN_80053c4c(0x44);
        }
      }
      else if (param_2 == 0) {
        pcVar1[(byte)pcVar1[0x2d8] + 0x2e4] = cVar4;
        if (pcVar1[0x2d9] == '\x1a') {
          pcVar1[0x2d8] = '\x01';
          FUN_80053c4c(0x59);
        }
        else {
          if (pcVar1[0x2d9] != '\x0f') {
            return 0;
          }
          pcVar1[0x2d8] = '\x01';
          FUN_80053c4c(0x4e);
        }
      }
      else {
        if (param_2 != 2) {
          return 0;
        }
        pcVar1[0x2d8] = '\x01';
      }
    }
    else if (pcVar1[0x2d9] != '\x1c') {
      if (pcVar1[0x2d9] == '\x1d') {
        if (pcVar1[0x2d8] != '\0') {
          *pcVar1 = *pcVar1 + -1;
          pcVar1[0x2d8] = pcVar1[0x2d8] + -1;
          FUN_80053c4c(0x20);
          return 0;
        }
      }
      else {
        if (param_1 <= (byte)pcVar1[0x2d8]) {
          return 0;
        }
        uVar5 = 0x2a;
        if (param_2 == 0) {
          uVar5 = FUN_80053994(pcVar1[0x2d9]);
        }
        FUN_80053c4c(uVar5);
        pcVar1[(byte)pcVar1[0x2d8] + 0x2e4] = pcVar1[0x2d9];
        *pcVar1 = *pcVar1 + '\x01';
        pcVar1[0x2d8] = pcVar1[0x2d8] + '\x01';
      }
      goto LAB_80053244;
    }
    FUN_800539a0(0,&DAT_800b8c00,local_18);
    uVar7 = 0;
    if (pcVar1[0x2d8] != '\0') {
      pcVar6 = pcVar1;
      do {
        uVar7 = uVar7 + 1;
        cVar4 = FUN_80053994(pcVar6[0x2e4]);
        pcVar6[0x2e4] = cVar4;
        pcVar6 = pcVar1 + uVar7;
      } while (uVar7 < (byte)pcVar1[0x2d8]);
    }
    uVar3 = 1;
    pcVar1[uVar7 + 0x2e4] = '\0';
    pcVar1[0x2d8] = '\0';
  }
  return uVar3;
}
