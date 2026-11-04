/* FUN_8017b630
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017b630  body 0x8017b630..0x8017cf0b  size 6364 B
 * body sha256 3e7eb1090ffef8637411cc01411bcb8447fe9b0087b5f11bb4374afe31049f64
 * provider record sha256 5f78ae8db9f91b0bc203c12576459d6eabbd5bb8c32c57815ccb42de5c1b649b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8017b630(void)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  
  puVar3 = (undefined4 *)func_0x8004d138(_DAT_8010b6d0,0);
  bVar2 = false;
  piVar9 = (int *)*puVar3;
  uVar8 = piVar9[3];
  uVar7 = piVar9[2];
  if (uVar8 == uVar7) {
    iVar4 = 0;
  }
  else {
    iVar4 = uVar8 - uVar7;
    if (uVar8 <= uVar7) {
      iVar4 = *piVar9 - (uVar7 - uVar8);
    }
  }
  iVar6 = 0;
  if (iVar4 != 0) {
    uVar7 = piVar9[3];
    if (uVar7 < 2) {
      iVar4 = *piVar9 - (2 - uVar7);
    }
    else {
      iVar4 = uVar7 - 2;
    }
    iVar6 = piVar9[1] + iVar4 * 4;
  }
  if (iVar6 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(ushort *)(iVar6 + 2) & 0x800;
  }
  bVar1 = false;
  if (uVar5 == 0) {
    piVar9 = (int *)*puVar3;
    iVar4 = piVar9[3];
    if (iVar4 == 0) {
      iVar4 = *piVar9;
    }
    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
    if (iVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(ushort *)(iVar4 + 2) & 0x800;
    }
    bVar1 = uVar5 != 0;
  }
  if (bVar1) {
    bVar2 = true;
  }
  else {
    piVar9 = (int *)*puVar3;
    uVar8 = piVar9[3];
    uVar7 = piVar9[2];
    if (uVar8 == uVar7) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar8 - uVar7;
      if (uVar8 <= uVar7) {
        iVar4 = *piVar9 - (uVar7 - uVar8);
      }
    }
    iVar6 = 0;
    if (iVar4 != 0) {
      uVar7 = piVar9[3];
      if (uVar7 < 2) {
        iVar4 = *piVar9 - (2 - uVar7);
      }
      else {
        iVar4 = uVar7 - 2;
      }
      iVar6 = piVar9[1] + iVar4 * 4;
    }
    if (iVar6 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(ushort *)(iVar6 + 2) & 0x400;
    }
    bVar1 = false;
    if (uVar5 == 0) {
      piVar9 = (int *)*puVar3;
      iVar4 = piVar9[3];
      if (iVar4 == 0) {
        iVar4 = *piVar9;
      }
      iVar4 = piVar9[1] + (iVar4 + -1) * 4;
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(ushort *)(iVar4 + 2) & 0x400;
      }
      bVar1 = uVar5 != 0;
    }
    if (bVar1) {
      bVar2 = true;
    }
    else {
      piVar9 = (int *)*puVar3;
      uVar8 = piVar9[3];
      uVar7 = piVar9[2];
      if (uVar8 == uVar7) {
        iVar4 = 0;
      }
      else {
        iVar4 = uVar8 - uVar7;
        if (uVar8 <= uVar7) {
          iVar4 = *piVar9 - (uVar7 - uVar8);
        }
      }
      iVar6 = 0;
      if (iVar4 != 0) {
        uVar7 = piVar9[3];
        if (uVar7 < 2) {
          iVar4 = *piVar9 - (2 - uVar7);
        }
        else {
          iVar4 = uVar7 - 2;
        }
        iVar6 = piVar9[1] + iVar4 * 4;
      }
      if (iVar6 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(ushort *)(iVar6 + 2) & 0x200;
      }
      bVar1 = false;
      if (uVar5 == 0) {
        piVar9 = (int *)*puVar3;
        iVar4 = piVar9[3];
        if (iVar4 == 0) {
          iVar4 = *piVar9;
        }
        iVar4 = piVar9[1] + (iVar4 + -1) * 4;
        if (iVar4 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(ushort *)(iVar4 + 2) & 0x200;
        }
        bVar1 = uVar5 != 0;
      }
      if (bVar1) {
        bVar2 = true;
      }
      else {
        piVar9 = (int *)*puVar3;
        uVar8 = piVar9[3];
        uVar7 = piVar9[2];
        if (uVar8 == uVar7) {
          iVar4 = 0;
        }
        else {
          iVar4 = uVar8 - uVar7;
          if (uVar8 <= uVar7) {
            iVar4 = *piVar9 - (uVar7 - uVar8);
          }
        }
        iVar6 = 0;
        if (iVar4 != 0) {
          uVar7 = piVar9[3];
          if (uVar7 < 2) {
            iVar4 = *piVar9 - (2 - uVar7);
          }
          else {
            iVar4 = uVar7 - 2;
          }
          iVar6 = piVar9[1] + iVar4 * 4;
        }
        if (iVar6 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(ushort *)(iVar6 + 2) & 0x100;
        }
        bVar1 = false;
        if (uVar5 == 0) {
          piVar9 = (int *)*puVar3;
          iVar4 = piVar9[3];
          if (iVar4 == 0) {
            iVar4 = *piVar9;
          }
          iVar4 = piVar9[1] + (iVar4 + -1) * 4;
          if (iVar4 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(ushort *)(iVar4 + 2) & 0x100;
          }
          bVar1 = uVar5 != 0;
        }
        if (bVar1) {
          bVar2 = true;
        }
        else {
          piVar9 = (int *)*puVar3;
          uVar8 = piVar9[3];
          uVar7 = piVar9[2];
          if (uVar8 == uVar7) {
            iVar4 = 0;
          }
          else {
            iVar4 = uVar8 - uVar7;
            if (uVar8 <= uVar7) {
              iVar4 = *piVar9 - (uVar7 - uVar8);
            }
          }
          iVar6 = 0;
          if (iVar4 != 0) {
            uVar7 = piVar9[3];
            if (uVar7 < 2) {
              iVar4 = *piVar9 - (2 - uVar7);
            }
            else {
              iVar4 = uVar7 - 2;
            }
            iVar6 = piVar9[1] + iVar4 * 4;
          }
          if (iVar6 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(ushort *)(iVar6 + 2) & 0x20;
          }
          bVar1 = false;
          if (uVar5 == 0) {
            piVar9 = (int *)*puVar3;
            iVar4 = piVar9[3];
            if (iVar4 == 0) {
              iVar4 = *piVar9;
            }
            iVar4 = piVar9[1] + (iVar4 + -1) * 4;
            if (iVar4 == 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = *(ushort *)(iVar4 + 2) & 0x20;
            }
            bVar1 = uVar5 != 0;
          }
          if (bVar1) {
            bVar2 = true;
          }
          else {
            piVar9 = (int *)*puVar3;
            uVar8 = piVar9[3];
            uVar7 = piVar9[2];
            if (uVar8 == uVar7) {
              iVar4 = 0;
            }
            else {
              iVar4 = uVar8 - uVar7;
              if (uVar8 <= uVar7) {
                iVar4 = *piVar9 - (uVar7 - uVar8);
              }
            }
            iVar6 = 0;
            if (iVar4 != 0) {
              uVar7 = piVar9[3];
              if (uVar7 < 2) {
                iVar4 = *piVar9 - (2 - uVar7);
              }
              else {
                iVar4 = uVar7 - 2;
              }
              iVar6 = piVar9[1] + iVar4 * 4;
            }
            if (iVar6 == 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = *(ushort *)(iVar6 + 2) & 0x10;
            }
            bVar1 = false;
            if (uVar5 == 0) {
              piVar9 = (int *)*puVar3;
              iVar4 = piVar9[3];
              if (iVar4 == 0) {
                iVar4 = *piVar9;
              }
              iVar4 = piVar9[1] + (iVar4 + -1) * 4;
              if (iVar4 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(ushort *)(iVar4 + 2) & 0x10;
              }
              bVar1 = uVar5 != 0;
            }
            if (bVar1) {
              bVar2 = true;
            }
            else {
              piVar9 = (int *)*puVar3;
              uVar8 = piVar9[3];
              uVar7 = piVar9[2];
              if (uVar8 == uVar7) {
                iVar4 = 0;
              }
              else {
                iVar4 = uVar8 - uVar7;
                if (uVar8 <= uVar7) {
                  iVar4 = *piVar9 - (uVar7 - uVar8);
                }
              }
              iVar6 = 0;
              if (iVar4 != 0) {
                uVar7 = piVar9[3];
                if (uVar7 < 2) {
                  iVar4 = *piVar9 - (2 - uVar7);
                }
                else {
                  iVar4 = uVar7 - 2;
                }
                iVar6 = piVar9[1] + iVar4 * 4;
              }
              if (iVar6 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(ushort *)(iVar6 + 2) & 8;
              }
              bVar1 = false;
              if (uVar5 == 0) {
                piVar9 = (int *)*puVar3;
                iVar4 = piVar9[3];
                if (iVar4 == 0) {
                  iVar4 = *piVar9;
                }
                iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                if (iVar4 == 0) {
                  uVar5 = 0;
                }
                else {
                  uVar5 = *(ushort *)(iVar4 + 2) & 8;
                }
                bVar1 = uVar5 != 0;
              }
              if (bVar1) {
                bVar2 = true;
              }
              else {
                piVar9 = (int *)*puVar3;
                uVar8 = piVar9[3];
                uVar7 = piVar9[2];
                if (uVar8 == uVar7) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = uVar8 - uVar7;
                  if (uVar8 <= uVar7) {
                    iVar4 = *piVar9 - (uVar7 - uVar8);
                  }
                }
                iVar6 = 0;
                if (iVar4 != 0) {
                  uVar7 = piVar9[3];
                  if (uVar7 < 2) {
                    iVar4 = *piVar9 - (2 - uVar7);
                  }
                  else {
                    iVar4 = uVar7 - 2;
                  }
                  iVar6 = piVar9[1] + iVar4 * 4;
                }
                if (iVar6 == 0) {
                  uVar5 = 0;
                }
                else {
                  uVar5 = *(ushort *)(iVar6 + 2) & 1;
                }
                bVar1 = false;
                if (uVar5 == 0) {
                  piVar9 = (int *)*puVar3;
                  iVar4 = piVar9[3];
                  if (iVar4 == 0) {
                    iVar4 = *piVar9;
                  }
                  iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                  if (iVar4 == 0) {
                    uVar5 = 0;
                  }
                  else {
                    uVar5 = *(ushort *)(iVar4 + 2) & 1;
                  }
                  bVar1 = uVar5 != 0;
                }
                if (bVar1) {
                  bVar2 = true;
                }
                else {
                  piVar9 = (int *)*puVar3;
                  uVar8 = piVar9[3];
                  uVar7 = piVar9[2];
                  if (uVar8 == uVar7) {
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = uVar8 - uVar7;
                    if (uVar8 <= uVar7) {
                      iVar4 = *piVar9 - (uVar7 - uVar8);
                    }
                  }
                  iVar6 = 0;
                  if (iVar4 != 0) {
                    uVar7 = piVar9[3];
                    if (uVar7 < 2) {
                      iVar4 = *piVar9 - (2 - uVar7);
                    }
                    else {
                      iVar4 = uVar7 - 2;
                    }
                    iVar6 = piVar9[1] + iVar4 * 4;
                  }
                  if (iVar6 == 0) {
                    uVar5 = 0;
                  }
                  else {
                    uVar5 = *(ushort *)(iVar6 + 2) & 2;
                  }
                  bVar1 = false;
                  if (uVar5 == 0) {
                    piVar9 = (int *)*puVar3;
                    iVar4 = piVar9[3];
                    if (iVar4 == 0) {
                      iVar4 = *piVar9;
                    }
                    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                    if (iVar4 == 0) {
                      uVar5 = 0;
                    }
                    else {
                      uVar5 = *(ushort *)(iVar4 + 2) & 2;
                    }
                    bVar1 = uVar5 != 0;
                  }
                  if (bVar1) {
                    bVar2 = true;
                  }
                  else {
                    piVar9 = (int *)*puVar3;
                    uVar8 = piVar9[3];
                    uVar7 = piVar9[2];
                    if (uVar8 == uVar7) {
                      iVar4 = 0;
                    }
                    else {
                      iVar4 = uVar8 - uVar7;
                      if (uVar8 <= uVar7) {
                        iVar4 = *piVar9 - (uVar7 - uVar8);
                      }
                    }
                    iVar6 = 0;
                    if (iVar4 != 0) {
                      uVar7 = piVar9[3];
                      if (uVar7 < 2) {
                        iVar4 = *piVar9 - (2 - uVar7);
                      }
                      else {
                        iVar4 = uVar7 - 2;
                      }
                      iVar6 = piVar9[1] + iVar4 * 4;
                    }
                    if (iVar6 == 0) {
                      uVar5 = 0;
                    }
                    else {
                      uVar5 = *(ushort *)(iVar6 + 2) & 4;
                    }
                    bVar1 = false;
                    if (uVar5 == 0) {
                      piVar9 = (int *)*puVar3;
                      iVar4 = piVar9[3];
                      if (iVar4 == 0) {
                        iVar4 = *piVar9;
                      }
                      iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                      if (iVar4 == 0) {
                        uVar5 = 0;
                      }
                      else {
                        uVar5 = *(ushort *)(iVar4 + 2) & 4;
                      }
                      bVar1 = uVar5 != 0;
                    }
                    if (bVar1) {
                      bVar2 = true;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  piVar9 = (int *)*puVar3;
  uVar8 = piVar9[3];
  uVar7 = piVar9[2];
  if (uVar8 == uVar7) {
    iVar4 = 0;
  }
  else {
    iVar4 = uVar8 - uVar7;
    if (uVar8 <= uVar7) {
      iVar4 = *piVar9 - (uVar7 - uVar8);
    }
  }
  iVar6 = 0;
  if (iVar4 != 0) {
    uVar7 = piVar9[3];
    if (uVar7 < 2) {
      iVar4 = *piVar9 - (2 - uVar7);
    }
    else {
      iVar4 = uVar7 - 2;
    }
    iVar6 = piVar9[1] + iVar4 * 4;
  }
  if (iVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)*(ushort *)(iVar6 + 2) & *(uint *)(&LAB_80180988 + DAT_80180ac0 * 4);
  }
  bVar1 = false;
  if (uVar7 == 0) {
    piVar9 = (int *)*puVar3;
    iVar4 = piVar9[3];
    if (iVar4 == 0) {
      iVar4 = *piVar9;
    }
    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
    if (iVar4 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (uint)*(ushort *)(iVar4 + 2) & *(uint *)(&LAB_80180988 + DAT_80180ac0 * 4);
    }
    bVar1 = uVar7 != 0;
  }
  if (bVar1) {
    DAT_80180ac0 = DAT_80180ac0 + 1;
    if (*(int *)(&LAB_80180988 + DAT_80180ac0 * 4) == 0) {
      _DAT_800e10ec = _DAT_800e10ec | 9;
      return 1;
    }
  }
  else if (bVar2) {
    DAT_80180ac0 = 0;
  }
  piVar9 = (int *)*puVar3;
  uVar8 = piVar9[3];
  uVar7 = piVar9[2];
  if (uVar8 == uVar7) {
    iVar4 = 0;
  }
  else {
    iVar4 = uVar8 - uVar7;
    if (uVar8 <= uVar7) {
      iVar4 = *piVar9 - (uVar7 - uVar8);
    }
  }
  iVar6 = 0;
  if (iVar4 != 0) {
    uVar7 = piVar9[3];
    if (uVar7 < 2) {
      iVar4 = *piVar9 - (2 - uVar7);
    }
    else {
      iVar4 = uVar7 - 2;
    }
    iVar6 = piVar9[1] + iVar4 * 4;
  }
  if (iVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)*(ushort *)(iVar6 + 2) & *(uint *)(&LAB_801809c4 + DAT_80180abc * 4);
  }
  bVar1 = false;
  if (uVar7 == 0) {
    piVar9 = (int *)*puVar3;
    iVar4 = piVar9[3];
    if (iVar4 == 0) {
      iVar4 = *piVar9;
    }
    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
    if (iVar4 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (uint)*(ushort *)(iVar4 + 2) & *(uint *)(&LAB_801809c4 + DAT_80180abc * 4);
    }
    bVar1 = uVar7 != 0;
  }
  if (bVar1) {
    DAT_80180abc = DAT_80180abc + 1;
    if (*(int *)(&LAB_801809c4 + DAT_80180abc * 4) == 0) {
      _DAT_800e10ec = _DAT_800e10ec & 0xfffffffe | 8;
      return 1;
    }
  }
  else if (bVar2) {
    DAT_80180abc = 0;
  }
  piVar9 = (int *)*puVar3;
  uVar8 = piVar9[3];
  uVar7 = piVar9[2];
  if (uVar8 == uVar7) {
    iVar4 = 0;
  }
  else {
    iVar4 = uVar8 - uVar7;
    if (uVar8 <= uVar7) {
      iVar4 = *piVar9 - (uVar7 - uVar8);
    }
  }
  iVar6 = 0;
  if (iVar4 != 0) {
    uVar7 = piVar9[3];
    if (uVar7 < 2) {
      iVar4 = *piVar9 - (2 - uVar7);
    }
    else {
      iVar4 = uVar7 - 2;
    }
    iVar6 = piVar9[1] + iVar4 * 4;
  }
  if (iVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)*(ushort *)(iVar6 + 2) & *(uint *)(&LAB_80180a00 + DAT_80180ac8 * 4);
  }
  bVar1 = false;
  if (uVar7 == 0) {
    piVar9 = (int *)*puVar3;
    iVar4 = piVar9[3];
    if (iVar4 == 0) {
      iVar4 = *piVar9;
    }
    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
    if (iVar4 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (uint)*(ushort *)(iVar4 + 2) & *(uint *)(&LAB_80180a00 + DAT_80180ac8 * 4);
    }
    bVar1 = uVar7 != 0;
  }
  if (bVar1) {
    DAT_80180ac8 = DAT_80180ac8 + 1;
    if (*(int *)(&LAB_80180a00 + DAT_80180ac8 * 4) == 0) {
      _DAT_8010dc34 = 1;
      return 1;
    }
  }
  else if (bVar2) {
    DAT_80180ac8 = 0;
  }
  piVar9 = (int *)*puVar3;
  uVar8 = piVar9[3];
  uVar7 = piVar9[2];
  if (uVar8 == uVar7) {
    iVar4 = 0;
  }
  else {
    iVar4 = uVar8 - uVar7;
    if (uVar8 <= uVar7) {
      iVar4 = *piVar9 - (uVar7 - uVar8);
    }
  }
  iVar6 = 0;
  if (iVar4 != 0) {
    uVar7 = piVar9[3];
    if (uVar7 < 2) {
      iVar4 = *piVar9 - (2 - uVar7);
    }
    else {
      iVar4 = uVar7 - 2;
    }
    iVar6 = piVar9[1] + iVar4 * 4;
  }
  if (iVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)*(ushort *)(iVar6 + 2) & *(uint *)(&DAT_80180a3c + DAT_80180acc * 4);
  }
  bVar1 = false;
  if (uVar7 == 0) {
    piVar9 = (int *)*puVar3;
    iVar4 = piVar9[3];
    if (iVar4 == 0) {
      iVar4 = *piVar9;
    }
    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
    if (iVar4 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (uint)*(ushort *)(iVar4 + 2) & *(uint *)(&DAT_80180a3c + DAT_80180acc * 4);
    }
    bVar1 = uVar7 != 0;
  }
  if (bVar1) {
    DAT_80180acc = DAT_80180acc + 1;
    if (*(int *)(&DAT_80180a3c + DAT_80180acc * 4) == 0) {
      _DAT_8012bebc = 1;
      return 1;
    }
  }
  else if (bVar2) {
    DAT_80180acc = 0;
  }
  puVar3 = (undefined4 *)func_0x8004d138(_DAT_8010b6d0,3);
  bVar2 = false;
  if (puVar3 != (undefined4 *)0x0) {
    bVar2 = false;
    piVar9 = (int *)*puVar3;
    uVar8 = piVar9[3];
    uVar7 = piVar9[2];
    if (uVar8 == uVar7) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar8 - uVar7;
      if (uVar8 <= uVar7) {
        iVar4 = *piVar9 - (uVar7 - uVar8);
      }
    }
    iVar6 = 0;
    if (iVar4 != 0) {
      uVar7 = piVar9[3];
      if (uVar7 < 2) {
        iVar4 = *piVar9 - (2 - uVar7);
      }
      else {
        iVar4 = uVar7 - 2;
      }
      iVar6 = piVar9[1] + iVar4 * 4;
    }
    if (iVar6 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(ushort *)(iVar6 + 2) & 0x800;
    }
    bVar1 = false;
    if (uVar5 == 0) {
      piVar9 = (int *)*puVar3;
      iVar4 = piVar9[3];
      if (iVar4 == 0) {
        iVar4 = *piVar9;
      }
      iVar4 = piVar9[1] + (iVar4 + -1) * 4;
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(ushort *)(iVar4 + 2) & 0x800;
      }
      bVar1 = uVar5 != 0;
    }
    if (bVar1) {
      bVar2 = true;
    }
    else {
      piVar9 = (int *)*puVar3;
      uVar8 = piVar9[3];
      uVar7 = piVar9[2];
      if (uVar8 == uVar7) {
        iVar4 = 0;
      }
      else {
        iVar4 = uVar8 - uVar7;
        if (uVar8 <= uVar7) {
          iVar4 = *piVar9 - (uVar7 - uVar8);
        }
      }
      iVar6 = 0;
      if (iVar4 != 0) {
        uVar7 = piVar9[3];
        if (uVar7 < 2) {
          iVar4 = *piVar9 - (2 - uVar7);
        }
        else {
          iVar4 = uVar7 - 2;
        }
        iVar6 = piVar9[1] + iVar4 * 4;
      }
      if (iVar6 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(ushort *)(iVar6 + 2) & 0x400;
      }
      bVar1 = false;
      if (uVar5 == 0) {
        piVar9 = (int *)*puVar3;
        iVar4 = piVar9[3];
        if (iVar4 == 0) {
          iVar4 = *piVar9;
        }
        iVar4 = piVar9[1] + (iVar4 + -1) * 4;
        if (iVar4 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(ushort *)(iVar4 + 2) & 0x400;
        }
        bVar1 = uVar5 != 0;
      }
      if (bVar1) {
        bVar2 = true;
      }
      else {
        piVar9 = (int *)*puVar3;
        uVar8 = piVar9[3];
        uVar7 = piVar9[2];
        if (uVar8 == uVar7) {
          iVar4 = 0;
        }
        else {
          iVar4 = uVar8 - uVar7;
          if (uVar8 <= uVar7) {
            iVar4 = *piVar9 - (uVar7 - uVar8);
          }
        }
        iVar6 = 0;
        if (iVar4 != 0) {
          uVar7 = piVar9[3];
          if (uVar7 < 2) {
            iVar4 = *piVar9 - (2 - uVar7);
          }
          else {
            iVar4 = uVar7 - 2;
          }
          iVar6 = piVar9[1] + iVar4 * 4;
        }
        if (iVar6 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(ushort *)(iVar6 + 2) & 0x200;
        }
        bVar1 = false;
        if (uVar5 == 0) {
          piVar9 = (int *)*puVar3;
          iVar4 = piVar9[3];
          if (iVar4 == 0) {
            iVar4 = *piVar9;
          }
          iVar4 = piVar9[1] + (iVar4 + -1) * 4;
          if (iVar4 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(ushort *)(iVar4 + 2) & 0x200;
          }
          bVar1 = uVar5 != 0;
        }
        if (bVar1) {
          bVar2 = true;
        }
        else {
          piVar9 = (int *)*puVar3;
          uVar8 = piVar9[3];
          uVar7 = piVar9[2];
          if (uVar8 == uVar7) {
            iVar4 = 0;
          }
          else {
            iVar4 = uVar8 - uVar7;
            if (uVar8 <= uVar7) {
              iVar4 = *piVar9 - (uVar7 - uVar8);
            }
          }
          iVar6 = 0;
          if (iVar4 != 0) {
            uVar7 = piVar9[3];
            if (uVar7 < 2) {
              iVar4 = *piVar9 - (2 - uVar7);
            }
            else {
              iVar4 = uVar7 - 2;
            }
            iVar6 = piVar9[1] + iVar4 * 4;
          }
          if (iVar6 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(ushort *)(iVar6 + 2) & 0x100;
          }
          bVar1 = false;
          if (uVar5 == 0) {
            piVar9 = (int *)*puVar3;
            iVar4 = piVar9[3];
            if (iVar4 == 0) {
              iVar4 = *piVar9;
            }
            iVar4 = piVar9[1] + (iVar4 + -1) * 4;
            if (iVar4 == 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = *(ushort *)(iVar4 + 2) & 0x100;
            }
            bVar1 = uVar5 != 0;
          }
          if (bVar1) {
            bVar2 = true;
          }
          else {
            piVar9 = (int *)*puVar3;
            uVar8 = piVar9[3];
            uVar7 = piVar9[2];
            if (uVar8 == uVar7) {
              iVar4 = 0;
            }
            else {
              iVar4 = uVar8 - uVar7;
              if (uVar8 <= uVar7) {
                iVar4 = *piVar9 - (uVar7 - uVar8);
              }
            }
            iVar6 = 0;
            if (iVar4 != 0) {
              uVar7 = piVar9[3];
              if (uVar7 < 2) {
                iVar4 = *piVar9 - (2 - uVar7);
              }
              else {
                iVar4 = uVar7 - 2;
              }
              iVar6 = piVar9[1] + iVar4 * 4;
            }
            if (iVar6 == 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = *(ushort *)(iVar6 + 2) & 0x20;
            }
            bVar1 = false;
            if (uVar5 == 0) {
              piVar9 = (int *)*puVar3;
              iVar4 = piVar9[3];
              if (iVar4 == 0) {
                iVar4 = *piVar9;
              }
              iVar4 = piVar9[1] + (iVar4 + -1) * 4;
              if (iVar4 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(ushort *)(iVar4 + 2) & 0x20;
              }
              bVar1 = uVar5 != 0;
            }
            if (bVar1) {
              bVar2 = true;
            }
            else {
              piVar9 = (int *)*puVar3;
              uVar8 = piVar9[3];
              uVar7 = piVar9[2];
              if (uVar8 == uVar7) {
                iVar4 = 0;
              }
              else {
                iVar4 = uVar8 - uVar7;
                if (uVar8 <= uVar7) {
                  iVar4 = *piVar9 - (uVar7 - uVar8);
                }
              }
              iVar6 = 0;
              if (iVar4 != 0) {
                uVar7 = piVar9[3];
                if (uVar7 < 2) {
                  iVar4 = *piVar9 - (2 - uVar7);
                }
                else {
                  iVar4 = uVar7 - 2;
                }
                iVar6 = piVar9[1] + iVar4 * 4;
              }
              if (iVar6 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(ushort *)(iVar6 + 2) & 0x10;
              }
              bVar1 = false;
              if (uVar5 == 0) {
                piVar9 = (int *)*puVar3;
                iVar4 = piVar9[3];
                if (iVar4 == 0) {
                  iVar4 = *piVar9;
                }
                iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                if (iVar4 == 0) {
                  uVar5 = 0;
                }
                else {
                  uVar5 = *(ushort *)(iVar4 + 2) & 0x10;
                }
                bVar1 = uVar5 != 0;
              }
              if (bVar1) {
                bVar2 = true;
              }
              else {
                piVar9 = (int *)*puVar3;
                uVar8 = piVar9[3];
                uVar7 = piVar9[2];
                if (uVar8 == uVar7) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = uVar8 - uVar7;
                  if (uVar8 <= uVar7) {
                    iVar4 = *piVar9 - (uVar7 - uVar8);
                  }
                }
                iVar6 = 0;
                if (iVar4 != 0) {
                  uVar7 = piVar9[3];
                  if (uVar7 < 2) {
                    iVar4 = *piVar9 - (2 - uVar7);
                  }
                  else {
                    iVar4 = uVar7 - 2;
                  }
                  iVar6 = piVar9[1] + iVar4 * 4;
                }
                if (iVar6 == 0) {
                  uVar5 = 0;
                }
                else {
                  uVar5 = *(ushort *)(iVar6 + 2) & 8;
                }
                bVar1 = false;
                if (uVar5 == 0) {
                  piVar9 = (int *)*puVar3;
                  iVar4 = piVar9[3];
                  if (iVar4 == 0) {
                    iVar4 = *piVar9;
                  }
                  iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                  if (iVar4 == 0) {
                    uVar5 = 0;
                  }
                  else {
                    uVar5 = *(ushort *)(iVar4 + 2) & 8;
                  }
                  bVar1 = uVar5 != 0;
                }
                if (bVar1) {
                  bVar2 = true;
                }
                else {
                  piVar9 = (int *)*puVar3;
                  uVar8 = piVar9[3];
                  uVar7 = piVar9[2];
                  if (uVar8 == uVar7) {
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = uVar8 - uVar7;
                    if (uVar8 <= uVar7) {
                      iVar4 = *piVar9 - (uVar7 - uVar8);
                    }
                  }
                  iVar6 = 0;
                  if (iVar4 != 0) {
                    uVar7 = piVar9[3];
                    if (uVar7 < 2) {
                      iVar4 = *piVar9 - (2 - uVar7);
                    }
                    else {
                      iVar4 = uVar7 - 2;
                    }
                    iVar6 = piVar9[1] + iVar4 * 4;
                  }
                  if (iVar6 == 0) {
                    uVar5 = 0;
                  }
                  else {
                    uVar5 = *(ushort *)(iVar6 + 2) & 1;
                  }
                  bVar1 = false;
                  if (uVar5 == 0) {
                    piVar9 = (int *)*puVar3;
                    iVar4 = piVar9[3];
                    if (iVar4 == 0) {
                      iVar4 = *piVar9;
                    }
                    iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                    if (iVar4 == 0) {
                      uVar5 = 0;
                    }
                    else {
                      uVar5 = *(ushort *)(iVar4 + 2) & 1;
                    }
                    bVar1 = uVar5 != 0;
                  }
                  if (bVar1) {
                    bVar2 = true;
                  }
                  else {
                    piVar9 = (int *)*puVar3;
                    uVar8 = piVar9[3];
                    uVar7 = piVar9[2];
                    if (uVar8 == uVar7) {
                      iVar4 = 0;
                    }
                    else {
                      iVar4 = uVar8 - uVar7;
                      if (uVar8 <= uVar7) {
                        iVar4 = *piVar9 - (uVar7 - uVar8);
                      }
                    }
                    iVar6 = 0;
                    if (iVar4 != 0) {
                      uVar7 = piVar9[3];
                      if (uVar7 < 2) {
                        iVar4 = *piVar9 - (2 - uVar7);
                      }
                      else {
                        iVar4 = uVar7 - 2;
                      }
                      iVar6 = piVar9[1] + iVar4 * 4;
                    }
                    if (iVar6 == 0) {
                      uVar5 = 0;
                    }
                    else {
                      uVar5 = *(ushort *)(iVar6 + 2) & 2;
                    }
                    bVar1 = false;
                    if (uVar5 == 0) {
                      piVar9 = (int *)*puVar3;
                      iVar4 = piVar9[3];
                      if (iVar4 == 0) {
                        iVar4 = *piVar9;
                      }
                      iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                      if (iVar4 == 0) {
                        uVar5 = 0;
                      }
                      else {
                        uVar5 = *(ushort *)(iVar4 + 2) & 2;
                      }
                      bVar1 = uVar5 != 0;
                    }
                    if (bVar1) {
                      bVar2 = true;
                    }
                    else {
                      piVar9 = (int *)*puVar3;
                      uVar8 = piVar9[3];
                      uVar7 = piVar9[2];
                      if (uVar8 == uVar7) {
                        iVar4 = 0;
                      }
                      else {
                        iVar4 = uVar8 - uVar7;
                        if (uVar8 <= uVar7) {
                          iVar4 = *piVar9 - (uVar7 - uVar8);
                        }
                      }
                      iVar6 = 0;
                      if (iVar4 != 0) {
                        uVar7 = piVar9[3];
                        if (uVar7 < 2) {
                          iVar4 = *piVar9 - (2 - uVar7);
                        }
                        else {
                          iVar4 = uVar7 - 2;
                        }
                        iVar6 = piVar9[1] + iVar4 * 4;
                      }
                      if (iVar6 == 0) {
                        uVar5 = 0;
                      }
                      else {
                        uVar5 = *(ushort *)(iVar6 + 2) & 4;
                      }
                      bVar1 = false;
                      if (uVar5 == 0) {
                        piVar9 = (int *)*puVar3;
                        iVar4 = piVar9[3];
                        if (iVar4 == 0) {
                          iVar4 = *piVar9;
                        }
                        iVar4 = piVar9[1] + (iVar4 + -1) * 4;
                        if (iVar4 == 0) {
                          uVar5 = 0;
                        }
                        else {
                          uVar5 = *(ushort *)(iVar4 + 2) & 4;
                        }
                        bVar1 = uVar5 != 0;
                      }
                      if (bVar1) {
                        bVar2 = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (puVar3 != (undefined4 *)0x0) {
      piVar9 = (int *)*puVar3;
      uVar8 = piVar9[3];
      uVar7 = piVar9[2];
      if (uVar8 == uVar7) {
        iVar4 = 0;
      }
      else {
        iVar4 = uVar8 - uVar7;
        if (uVar8 <= uVar7) {
          iVar4 = *piVar9 - (uVar7 - uVar8);
        }
      }
      iVar6 = 0;
      if (iVar4 != 0) {
        uVar7 = piVar9[3];
        if (uVar7 < 2) {
          iVar4 = *piVar9 - (2 - uVar7);
        }
        else {
          iVar4 = uVar7 - 2;
        }
        iVar6 = piVar9[1] + iVar4 * 4;
      }
      if (iVar6 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = (uint)*(ushort *)(iVar6 + 2) & *(uint *)(&DAT_80180a78 + DAT_80180ac4 * 4);
      }
      bVar1 = false;
      if (uVar7 == 0) {
        piVar9 = (int *)*puVar3;
        iVar4 = piVar9[3];
        if (iVar4 == 0) {
          iVar4 = *piVar9;
        }
        iVar4 = piVar9[1] + (iVar4 + -1) * 4;
        if (iVar4 == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = (uint)*(ushort *)(iVar4 + 2) & *(uint *)(&DAT_80180a78 + DAT_80180ac4 * 4);
        }
        bVar1 = uVar7 != 0;
      }
      if (bVar1) {
        DAT_80180ac4 = DAT_80180ac4 + 1;
        if (*(int *)(&DAT_80180a78 + DAT_80180ac4 * 4) == 0) {
          _DAT_800c4eac = 1;
          _DAT_800c4f64 = 1;
          _DAT_80131f10 = 1;
          return 1;
        }
        return 0;
      }
    }
  }
  if (bVar2) {
    DAT_80180ac4 = 0;
  }
  return 0;
}
