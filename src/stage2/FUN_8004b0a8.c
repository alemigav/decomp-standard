/* FUN_8004b0a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004b0a8  body 0x8004b0a8..0x8004b6cf  size 700 B
 * body sha256 f298ab23efd5993ba95bd4af6e049b894d5a9e19d58d74883c68bcafa586f97e
 * provider record sha256 e6832568a0ebeba7ae470c24a5b5015ab0e87393dbbdb7c693812907c981399c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8004b204) */

void FUN_8004b0a8(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  
  pbVar6 = *(byte **)(param_1 + 0xd018);
  bVar1 = DAT_800e9182 == '\0';
  switch(*(undefined1 *)(param_1 + 0xd00d)) {
  case 0:
    *(undefined1 *)(param_1 + 0xd00d) = 1;
    uVar2 = (undefined1)(1 << bVar1);
    *(undefined1 *)(param_1 + 0xd011) = uVar2;
    *(undefined1 *)(param_1 + 0xd010) = uVar2;
    *(undefined1 *)(param_1 + 0xd012) = 0;
    *(undefined1 *)(param_1 + 0xd013) = 0;
    pbVar6 = *(byte **)(param_1 + 0xd014);
    DAT_800e110c = DAT_800e110c & 0xffffffbf;
    DAT_800e1110 = DAT_800e1110 | *(uint *)(param_1 + 0xd030);
  case 1:
    iVar8 = 1;
    cVar4 = *(char *)(param_1 + 0xd011);
    *(char *)(param_1 + 0xd011) = cVar4 + -1;
    if ((*(char *)(param_1 + 0xd00e) == '\0') || (bVar3 = cVar4 - 4, (DAT_800df914 & 0x3000) == 0))
    goto LAB_8004b210;
    *(byte *)(param_1 + 0xd011) = bVar3;
    if (0 < (int)((uint)bVar3 << 0x18)) break;
    bVar3 = *(byte *)(param_1 + 0xd010);
    if (bVar3 == 2) {
LAB_8004b1fc:
      iVar8 = 2;
    }
    else if (bVar3 < 3) {
      iVar8 = 4;
    }
    else if (bVar3 == 3) goto LAB_8004b1fc;
LAB_8004b210:
    if (*(char *)(param_1 + 0xd011) < '\x01') {
      do {
        if (0xec < (byte)(*pbVar6 - 1)) {
          do {
            bVar3 = *pbVar6;
            if (bVar3 == 0xf8) {
              *(byte **)(param_1 + 0xd01c) = pbVar6;
              bVar3 = pbVar6[1];
              if (bVar3 == 0) {
                bVar3 = *(byte *)(param_1 + 0xd00f);
              }
              pbVar6 = (byte *)FUN_8004bad8(bVar3);
            }
            else if (bVar3 < 0xf9) {
              if (bVar3 < 0xf1) {
                if (0xed < bVar3) {
                  pbVar6 = pbVar6 + 1;
                  break;
                }
                if (bVar3 == 0) {
                  pbVar6 = pbVar6 + 1;
                }
              }
              else {
                pbVar7 = pbVar6;
                if (bVar3 == 0xf5) {
LAB_8004b414:
                  pbVar6 = pbVar7 + 1;
                }
                else if (bVar3 == 0xf7) {
                  pbVar6 = (byte *)(*(int *)(param_1 + 0xd01c) + 2);
                }
              }
            }
            else {
              if (bVar3 == 0xfb) {
                *(undefined1 *)(param_1 + 0xd00d) = 4;
                *(char *)(param_1 + 0xd02a) = (char)(8 << bVar1);
                goto switchD_8004b108_default;
              }
              if (bVar3 < 0xfc) {
                if (bVar3 == 0xf9) {
                  pbVar7 = pbVar6 + 1;
                  pbVar6 = pbVar6 + 2;
                  *(byte *)(param_1 + 0xd013) = *pbVar7;
                }
                else if (bVar3 == 0xfa) {
                  pbVar7 = pbVar6 + 1;
                  bVar3 = *pbVar7;
                  if (bVar3 == 0) {
                    pbVar7 = pbVar6 + 2;
                    if (*pbVar7 == 0xfa) {
                      pbVar7 = pbVar6 + 3;
                    }
                    else {
                      do {
                        bVar3 = *pbVar7;
                        if (bVar3 < 0xee) {
                          pbVar7 = pbVar7 + 1;
                        }
                        else {
                          if (bVar3 < 0xf1) {
                            pbVar7 = pbVar7 + 1;
                          }
                          else if ((bVar3 < 0xfa) && (pbVar7 = pbVar7 + 1, bVar3 < 0xf8))
                          goto LAB_8004b398;
                          pbVar7 = pbVar7 + 1;
                        }
LAB_8004b398:
                      } while (*pbVar7 != 0xfa);
                      pbVar7 = pbVar7 + 1;
                    }
                    bVar3 = *pbVar7;
                  }
                  if (bVar3 < 2) {
                    *(char *)(param_1 + 0xd010) = (char)(1 << bVar1);
                  }
                  else {
                    *(byte *)(param_1 + 0xd010) = (*pbVar7 >> 1) << bVar1;
                  }
                  goto LAB_8004b414;
                }
              }
              else {
                if (bVar3 == 0xfd) {
                  if (pbVar6[1] == 0) {
                    *(undefined1 *)(param_1 + 0xd00d) = 2;
                  }
                  else {
                    *(undefined1 *)(param_1 + 0xd00d) = 3;
                    *(byte *)(param_1 + 0xd011) = pbVar6[1] << bVar1;
                  }
                  pbVar6 = pbVar6 + 2;
                  goto switchD_8004b108_default;
                }
                if (bVar3 < 0xfd) {
                  pbVar6 = pbVar6 + 1;
                }
                else if (bVar3 == 0xfe) {
                  pbVar6 = pbVar6 + 1;
                  if (*pbVar6 == 0) {
                    *(undefined1 *)(param_1 + 0xd00d) = 5;
                  }
                  else {
                    *(undefined1 *)(param_1 + 0xd00d) = 6;
                    *(byte *)(param_1 + 0xd011) = *pbVar6 << bVar1;
                  }
                  goto switchD_8004b108_default;
                }
              }
            }
          } while (0xec < (byte)(*pbVar6 - 1));
        }
        if (*pbVar6 != 0) {
          *(byte *)(param_1 + 0xd00c) = *(byte *)(param_1 + 0xd00c) | 0x40;
        }
        pbVar6 = pbVar6 + 1;
        if ((*(byte *)(param_1 + 0xd00c) & 0x40) != 0) {
          iVar8 = iVar8 + -1;
        }
      } while (iVar8 != 0);
      *(undefined1 *)(param_1 + 0xd011) = *(undefined1 *)(param_1 + 0xd010);
    }
    break;
  case 2:
    if ((DAT_800df918 & 0x1000) == 0) {
      cVar4 = *(char *)(param_1 + 0xd011) + -1;
      *(char *)(param_1 + 0xd011) = cVar4;
      if (((int)cVar4 & 0x18 << bVar1) != 0) {
        if ((*(ushort *)(param_1 + 0xd028) & 0x400) == 0) {
          FUN_8004a7c8(0x99,*(ushort *)(param_1 + 0xd026) + 0x1c,0,3,&DAT_800b8a40,0);
        }
        else {
          FUN_8004a7c8(0x6b,*(ushort *)(param_1 + 0xd026) + 0x2a,0,3,&DAT_800b8a40,0);
        }
      }
    }
    else {
      DAT_800df914 = 0xffff;
      *(undefined1 *)(param_1 + 0xd00d) = 1;
      *(byte **)(param_1 + 0xd014) = pbVar6;
      *(char *)(param_1 + 0xd011) = (char)(1 << bVar1);
      *(undefined1 *)(param_1 + 0xd012) = *(undefined1 *)(param_1 + 0xd013);
    }
    break;
  case 3:
    cVar4 = *(char *)(param_1 + 0xd011);
    *(char *)(param_1 + 0xd011) = cVar4 + -1;
    if (cVar4 == '\x01') {
      *(undefined1 *)(param_1 + 0xd00d) = 1;
      *(byte **)(param_1 + 0xd014) = pbVar6;
      *(char *)(param_1 + 0xd011) = *(char *)(param_1 + 0xd010) << bVar1;
      *(undefined1 *)(param_1 + 0xd012) = *(undefined1 *)(param_1 + 0xd013);
    }
    break;
  case 4:
    uVar5 = (uint)pbVar6[1];
    if ((DAT_800e10ec & 0x40) == 0) {
      FUN_8004b728(param_1,&UNK_800f9f70 + (uVar5 & 0xf) * 6,uVar5,0);
    }
    else {
      FUN_8004b728(param_1,&UNK_800f9f9c + (uVar5 & 0xf) * 6,uVar5,1);
    }
    break;
  case 5:
    if ((DAT_800df918 & 0x3000) != 0) {
      DAT_800df914 = 0xffff;
      *(byte *)(param_1 + 0xd00c) = *(byte *)(param_1 + 0xd00c) & 0x7f;
      DAT_800e1110 = *(undefined4 *)(param_1 + 0xd02c);
      return;
    }
    break;
  case 6:
    cVar4 = *(char *)(param_1 + 0xd011);
    *(char *)(param_1 + 0xd011) = cVar4 + -1;
    if (cVar4 == '\x01') {
      *(byte *)(param_1 + 0xd00c) = *(byte *)(param_1 + 0xd00c) & 0x7f;
      if (DAT_800e1110 == 0) {
        return;
      }
      DAT_800e1110 = *(undefined4 *)(param_1 + 0xd02c);
      return;
    }
  }
switchD_8004b108_default:
  *(byte **)(param_1 + 0xd018) = pbVar6;
  FUN_8004bbf4(param_1);
  return;
}
