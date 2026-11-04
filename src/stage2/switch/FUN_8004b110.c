/* FUN_8004b110
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004b110  body 0x8004b110..0x8004b727  size 964 B
 * body sha256 105d33520a5a4d26985949587f976b3c9cdce2612850d9e15c1e3fda27da95d3
 * provider record sha256 964568771d565ec4cf564ded2c16ddc0576e1ba0533910e9c8d4aba9e6625c40
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8004b204) */

void switchD_8004b108::caseD_0(void)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  uint unaff_s3;
  int unaff_s4;
  
  *(undefined1 *)(unaff_s4 + 0xd00d) = 1;
  uVar2 = (undefined1)(1 << (unaff_s3 & 0x1f));
  *(undefined1 *)(unaff_s4 + 0xd011) = uVar2;
  *(undefined1 *)(unaff_s4 + 0xd010) = uVar2;
  *(undefined1 *)(unaff_s4 + 0xd012) = 0;
  *(undefined1 *)(unaff_s4 + 0xd013) = 0;
  pbVar4 = *(byte **)(unaff_s4 + 0xd014);
  DAT_800e110c = DAT_800e110c & 0xffffffbf;
  DAT_800e1110 = DAT_800e1110 | *(uint *)(unaff_s4 + 0xd030);
  iVar6 = 1;
  cVar1 = *(char *)(unaff_s4 + 0xd011);
  *(char *)(unaff_s4 + 0xd011) = cVar1 + -1;
  if ((*(char *)(unaff_s4 + 0xd00e) == '\0') || (bVar3 = cVar1 - 4, (DAT_800df914 & 0x3000) == 0))
  goto LAB_8004b210;
  *(byte *)(unaff_s4 + 0xd011) = bVar3;
  if (0 < (int)((uint)bVar3 << 0x18)) goto switchD_8004b108_default;
  bVar3 = *(byte *)(unaff_s4 + 0xd010);
  if (bVar3 == 2) {
LAB_8004b1fc:
    iVar6 = 2;
  }
  else if (bVar3 < 3) {
    iVar6 = 4;
  }
  else if (bVar3 == 3) goto LAB_8004b1fc;
LAB_8004b210:
  if (*(char *)(unaff_s4 + 0xd011) < '\x01') {
    do {
      if (0xec < (byte)(*pbVar4 - 1)) {
        do {
          bVar3 = *pbVar4;
          if (bVar3 == 0xf8) {
            *(byte **)(unaff_s4 + 0xd01c) = pbVar4;
            bVar3 = pbVar4[1];
            if (bVar3 == 0) {
              bVar3 = *(byte *)(unaff_s4 + 0xd00f);
            }
            pbVar4 = (byte *)FUN_8004bad8(bVar3);
          }
          else if (bVar3 < 0xf9) {
            if (bVar3 < 0xf1) {
              if (0xed < bVar3) {
                pbVar4 = pbVar4 + 1;
                break;
              }
              if (bVar3 == 0) {
                pbVar4 = pbVar4 + 1;
              }
            }
            else {
              pbVar5 = pbVar4;
              if (bVar3 == 0xf5) {
LAB_8004b414:
                pbVar4 = pbVar5 + 1;
              }
              else if (bVar3 == 0xf7) {
                pbVar4 = (byte *)(*(int *)(unaff_s4 + 0xd01c) + 2);
              }
            }
          }
          else {
            if (bVar3 == 0xfb) {
              *(undefined1 *)(unaff_s4 + 0xd00d) = 4;
              *(char *)(unaff_s4 + 0xd02a) = (char)(8 << (unaff_s3 & 0x1f));
              goto switchD_8004b108_default;
            }
            if (bVar3 < 0xfc) {
              if (bVar3 == 0xf9) {
                pbVar5 = pbVar4 + 1;
                pbVar4 = pbVar4 + 2;
                *(byte *)(unaff_s4 + 0xd013) = *pbVar5;
              }
              else if (bVar3 == 0xfa) {
                pbVar5 = pbVar4 + 1;
                bVar3 = *pbVar5;
                if (bVar3 == 0) {
                  pbVar5 = pbVar4 + 2;
                  if (*pbVar5 == 0xfa) {
                    pbVar5 = pbVar4 + 3;
                  }
                  else {
                    do {
                      bVar3 = *pbVar5;
                      if (bVar3 < 0xee) {
                        pbVar5 = pbVar5 + 1;
                      }
                      else {
                        if (bVar3 < 0xf1) {
                          pbVar5 = pbVar5 + 1;
                        }
                        else if ((bVar3 < 0xfa) && (pbVar5 = pbVar5 + 1, bVar3 < 0xf8))
                        goto LAB_8004b398;
                        pbVar5 = pbVar5 + 1;
                      }
LAB_8004b398:
                    } while (*pbVar5 != 0xfa);
                    pbVar5 = pbVar5 + 1;
                  }
                  bVar3 = *pbVar5;
                }
                if (bVar3 < 2) {
                  *(char *)(unaff_s4 + 0xd010) = (char)(1 << (unaff_s3 & 0x1f));
                }
                else {
                  *(byte *)(unaff_s4 + 0xd010) = (*pbVar5 >> 1) << (unaff_s3 & 0x1f);
                }
                goto LAB_8004b414;
              }
            }
            else {
              if (bVar3 == 0xfd) {
                if (pbVar4[1] == 0) {
                  *(undefined1 *)(unaff_s4 + 0xd00d) = 2;
                }
                else {
                  *(undefined1 *)(unaff_s4 + 0xd00d) = 3;
                  *(byte *)(unaff_s4 + 0xd011) = pbVar4[1] << (unaff_s3 & 0x1f);
                }
                pbVar4 = pbVar4 + 2;
                goto switchD_8004b108_default;
              }
              if (bVar3 < 0xfd) {
                pbVar4 = pbVar4 + 1;
              }
              else if (bVar3 == 0xfe) {
                pbVar4 = pbVar4 + 1;
                if (*pbVar4 == 0) {
                  *(undefined1 *)(unaff_s4 + 0xd00d) = 5;
                }
                else {
                  *(undefined1 *)(unaff_s4 + 0xd00d) = 6;
                  *(byte *)(unaff_s4 + 0xd011) = *pbVar4 << (unaff_s3 & 0x1f);
                }
                goto switchD_8004b108_default;
              }
            }
          }
        } while (0xec < (byte)(*pbVar4 - 1));
      }
      if (*pbVar4 != 0) {
        *(byte *)(unaff_s4 + 0xd00c) = *(byte *)(unaff_s4 + 0xd00c) | 0x40;
      }
      pbVar4 = pbVar4 + 1;
      if ((*(byte *)(unaff_s4 + 0xd00c) & 0x40) != 0) {
        iVar6 = iVar6 + -1;
      }
    } while (iVar6 != 0);
    *(undefined1 *)(unaff_s4 + 0xd011) = *(undefined1 *)(unaff_s4 + 0xd010);
  }
switchD_8004b108_default:
  *(byte **)(unaff_s4 + 0xd018) = pbVar4;
  FUN_8004bbf4();
  return;
}
