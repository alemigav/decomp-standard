/* FUN_80099ed4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80099ed4  body 0x800996b4..0x8009aceb  size 4568 B
 * body sha256 78f13ebd2ec66ec03ed485840ba696876a2b8f9549749cfb66714acc82a6adf9
 * provider record sha256 62fcce24a696cf5ff3f0c1521ba026c93abe7492dbdfbb0ee283c01e9372e4f2
 * callees 45 direct (44 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80099714) */
/* WARNING: Removing unreachable block (ram,0x80099758) */
/* WARNING: Removing unreachable block (ram,0x80099724) */
/* WARNING: Removing unreachable block (ram,0x8009973c) */
/* WARNING: Removing unreachable block (ram,0x80099784) */
/* WARNING: Removing unreachable block (ram,0x80099744) */
/* WARNING: Removing unreachable block (ram,0x8009972c) */
/* WARNING: Removing unreachable block (ram,0x80099770) */
/* WARNING: Removing unreachable block (ram,0x80099734) */
/* WARNING: Removing unreachable block (ram,0x80099788) */
/* WARNING: Removing unreachable block (ram,0x80099794) */
/* WARNING: Removing unreachable block (ram,0x800997d4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80099ed4(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint unaff_s6;
  ushort in_stack_00000046;
  
code_r0x80099ed4:
  FUN_8004cd54(1,FUN_80052f40);
  DAT_80131780 = '\0';
  do {
    if ((DAT_800e10ec & 0x200000) != 0) {
      FUN_800274e4(2,1);
    }
    FUN_8004cd88(1);
    if ((DAT_800e10ec & 0x200000) != 0) {
      overlay_slot_reader_b(6);
    }
    if ((DAT_800e10ec & 0x40000000) == 0) {
      if (((((DAT_800e10ec & 8) == 0) && ((DAT_800e110c & 0x40000000) == 0)) &&
          ((DAT_800e10ec & 0x20080) == 0x20000)) &&
         (iVar4 = FUN_800837ac(&DAT_800e8ce0,6), iVar4 == 0)) {
        DAT_800e10ec = DAT_800e10ec | 0x80;
      }
      goto LAB_8009ac18;
    }
    if (DAT_80110e20 != 0) {
      FUN_8004a7a0(10,0x32,0,0);
    }
    DAT_801317c0 = 0;
    if (DAT_800e9240 == '\0') {
      uVar3 = unaff_s6 + 1;
      if ((DAT_800e10ec & 4) == 0) {
        if ((((DAT_800e10ec & 0x2000) != 0) && (DAT_80131780 == '\0')) && (DAT_800e8606 != 0)) {
          DAT_800e8b3e = 0;
          DAT_800e1110 = DAT_800e1110 | 0xff000000;
          if (DAT_800e9243 == '\0') {
            uVar7 = 0x200;
          }
          else {
            uVar7 = 0x800;
          }
          FUN_800274f8(0x200,uVar7,7,1);
          DAT_80131780 = '\x02';
        }
        switch(DAT_80131780) {
        case '\x01':
          if (((DAT_8010b294 & 0x80) == 0) && (iVar4 = FUN_8002767c(0), iVar4 != 0)) {
            DAT_800e1110 = DAT_800e1110 | 0xff000000;
            if (((DAT_800e110c & 0x8000) != 0) || ((DAT_800e10ec & 0x40000) != 0)) {
              FUN_800274f8(0x200,0x1800,7,1);
              DAT_80131780 = '\x02';
              goto FUN_80099b4c;
            }
            DAT_800e10ec = DAT_800e10ec | 0x10000;
            FUN_800274e4(1,0);
            DAT_800e1110 = 0;
            _DAT_8013a3f0 = 0;
            DAT_800e10ec = DAT_800e10ec | 0x4000;
            FUN_8009ad3c();
            goto LAB_80099d64;
          }
          break;
        case '\x02':
FUN_80099b4c:
          iVar4 = FUN_8002767c(0);
          if (iVar4 != 0) {
            FUN_800274f8(0x200,0,7,1);
            FUN_800275c0(0,0x7fff,0xffff,0);
            FUN_8004cd88(2);
            if (((DAT_800e10ec & 0x2000) != 0) && (DAT_800e8606 != 0)) {
              FUN_80075ef8();
LAB_8009ac18:
              FUN_80052df4();
              FUN_800274e4(2,1);
              DAT_8010bfa8 = DAT_8010bfa8 >> 1;
              if (((DAT_800e10ec & 0x2000) == 0) || (DAT_800e9243 != '\0')) {
                DAT_800e9243 = '\x01';
                FUN_80027874();
              }
              else {
                FUN_80027874();
                DAT_800e9241 = 0;
                DAT_800e10ec = DAT_800e10ec | 2;
                FUN_8004cd54(1,FUN_8009acec);
              }
              FUN_8004ce40(0x8015b030);
              return;
            }
            DAT_800e1110 = 0;
            _DAT_8013a3f0 = 0;
            if ((DAT_800e110c & 0x8000) == 0) {
              uVar3 = DAT_800e10ec | 0x4000;
              if ((DAT_800e10ec & 0x40000) != 0) {
                DAT_800e10ec = DAT_800e10ec & 0xfffbffff | 0x4000;
                overlay_slot_reader(1,2);
                _DAT_8013a3f0 = DAT_801317c4;
                DAT_801317c4 = 0;
                FUN_8004cd88(1);
                DAT_80131780 = 3;
                DAT_800e10ec = DAT_800e10ec & 0xfffffbff;
                FUN_80099d2c();
                return;
              }
            }
            else {
              if ((DAT_800e10ec & 0x8000000) == 0) {
                DAT_800e10ec = DAT_800e10ec | 0x4000;
                FUN_80052df4();
                DAT_800e90f8 = 1;
                overlay_slot_reader(1,8);
                FUN_8004cd88(1);
              }
              else {
                DAT_800e10ec = DAT_800e10ec & 0xf7ffffff | 0x4000;
                FUN_80052df4();
                DAT_800e90f8 = 1;
                overlay_slot_reader(1,4);
              }
              _DAT_8013a3f0 = DAT_801317c4;
              DAT_801317c4 = 0;
              DAT_800e110c = DAT_800e110c & 0xffff7fbf;
              uVar3 = DAT_800e10ec;
            }
            DAT_800e10ec = uVar3;
            FUN_8004cd88(1);
            DAT_80131780 = '\x03';
            goto code_r0x80099d2c;
          }
          break;
        case '\x03':
code_r0x80099d2c:
          DAT_800df938 = &DAT_800e1130;
          DAT_800e1134 = 0;
          FUN_800559b0();
LAB_80099d64:
          _DAT_8013a3f0 = _DAT_8013a3f0 | DAT_800e1110;
          DAT_800e10ec = DAT_800e10ec & 0xffffbfff;
          DAT_800e1110 = DAT_800e1110 | 0xef000000;
          iVar4 = FUN_8009b224();
          if (iVar4 == 0) {
            FUN_800274f8(0x200,0xffffe800,7,1);
          }
          if (((DAT_800e10ec & 8) != 0) && (_DAT_800e8ca8 == 0x1c)) {
            uVar3 = unaff_s6 & 0xffff;
            unaff_s6 = unaff_s6 - 1;
            if (uVar3 == 0) {
              unaff_s6 = 0x1d;
              DAT_800e8cbe = DAT_800e8cbe + -1;
            }
            in_stack_00000046 = (ushort)unaff_s6;
          }
          DAT_80131780 = '\x05';
          break;
        case '\x04':
          DAT_80131780 = '\x05';
          DAT_800e1110 = DAT_800e1110 | 0xff000000;
          break;
        case '\x05':
          iVar4 = FUN_8002767c(0);
          if (iVar4 == 0) {
            DAT_800e1110 = _DAT_8013a3f0;
            DAT_80131780 = '\0';
          }
          break;
        case '\x06':
          while (DAT_80131780 == '\x06') {
            FUN_8004cd88(1);
          }
          break;
        case '\a':
          goto code_r0x80099ed4;
        }
        if ((DAT_800e110c & 0x1000000) == 0) {
          if ((DAT_800e110c & 0x8000000) != 0) {
            uVar7 = 1;
            if ((DAT_800e10ec & 8) == 0) {
              if ((0x1d < (short)unaff_s6) || ((_DAT_8013a3f4 & 0x8000000) == 0)) {
                unaff_s6 = 0;
                in_stack_00000046 = 8;
                DAT_800e8cbe = DAT_800e8cbe + -1;
              }
              if (DAT_800e8cbe < 0x3c) {
                uVar7 = 2;
              }
              if (DAT_800e8cbe < 0) {
                FUN_8004a7c8(0x68,0x20,2,0);
              }
              else {
                FUN_8004a7c8(0x68,0x20,uVar7);
              }
              if (DAT_800e8cbe < 0) {
                bVar2 = false;
                if ((DAT_80131780 == '\0') && (iVar4 = FUN_8002767c(0), iVar4 != 0)) {
                  iVar4 = FUN_8004cef8(1);
                  bVar2 = iVar4 == 0;
                }
                if (bVar2) {
                  unaff_s6 = 0;
                  in_stack_00000046 = 0;
                  DAT_800e110c = DAT_800e110c & 0xf7ffffff;
                  DAT_800e10ec = DAT_800e10ec | 4;
                }
                goto LAB_8009a8a8;
              }
              if ((DAT_80131780 == '\0') && (iVar4 = FUN_8002767c(0), iVar4 != 0)) {
                in_stack_00000046 = in_stack_00000046 - 3;
                unaff_s6 = unaff_s6 + 1;
                if ((int)((uint)in_stack_00000046 << 0x10) < 1) goto LAB_8009a450;
              }
            }
            else {
              if ((0x1d < (short)unaff_s6) || ((_DAT_8013a3f4 & 0x8000000) == 0)) {
                unaff_s6 = 0;
                in_stack_00000046 = 0;
                DAT_800e8cbe = DAT_800e8cbe + 1;
              }
              FUN_8004a7c8(0x68,0x20,0,2);
              if ((DAT_800e8cbe == 5999) && ((short)unaff_s6 == 0x1b)) {
LAB_8009a450:
                in_stack_00000046 = 8;
              }
              else if ((DAT_80131780 == '\0') &&
                      ((iVar4 = FUN_8002767c(0), iVar4 != 0 && (_DAT_800e8ca8 != 0x1c)))) {
                in_stack_00000046 = (ushort)(unaff_s6 + 1);
                unaff_s6 = unaff_s6 + 1;
              }
            }
          }
          _DAT_8013a3f4 = DAT_800e110c;
          if (DAT_800e8924 != (code *)0x0) {
            (*DAT_800e8924)();
          }
          if ((DAT_800e110c & 0x100) == 0) {
            FUN_80083afc(0);
          }
          FUN_8006d998();
          iVar4 = FUN_8004cef8(1);
          if ((((iVar4 == 0) && (DAT_800e9183 == '\0')) && (DAT_80131780 == '\0')) &&
             ((((DAT_800e110c & 0x40) == 0 && ((DAT_800e1110 & 0x1000000) == 0)) &&
              ((DAT_800e139f == '\0' && ((DAT_800e10ec & 0x4000200) == 0)))))) {
            if (((DAT_800df90e & 0x100) != 0) && ((DAT_800e110c & 0x8000) == 0)) {
              DAT_800e10ec = DAT_800e10ec | 0x8000000;
              DAT_800e110c = DAT_800e110c | 0x8000;
            }
            if (((DAT_800df918 & 0x4000) != 0) && ((DAT_800e110c & 0x10) == 0)) {
              DAT_800e110c = DAT_800e110c | 0x8000;
            }
            if (((DAT_800df90e & 2) != 0) && ((DAT_800e110c & 0x10) == 0)) {
              DAT_800e110c = DAT_800e110c | 0x8000;
              DAT_8012bfa8 = '\x03';
            }
            uVar3 = DAT_800e110c | 0x40;
            if ((DAT_800e110c & 0x8000) != 0) {
              DAT_80131780 = '\x01';
              DAT_801317c4 = DAT_800e1110;
              DAT_800e1110 = DAT_800e1110 | 0xff000000;
              DAT_800e110c = uVar3;
              if (DAT_8012bfa8 != '\x02') {
                FUN_80077adc(0x4060000,0);
              }
              goto LAB_8009a8a8;
            }
          }
          FUN_80083ac4();
          DAT_801317c0 = DAT_801317c0 | 1;
          puVar9 = &DAT_800e13ec;
          DAT_800e1128 = DAT_800e1128 & 0xff;
          if (DAT_800df93c != &DAT_800e13ec) {
            do {
              puVar8 = (uint *)*puVar9;
              if (((*puVar8 & 1) != 0) && ((*(ushort *)((int)puVar8 + 0x1aa) & 0x8000) == 0)) {
                DAT_800df938 = puVar8;
                uVar3 = FUN_80040bb4((puVar8[10] - DAT_800e1158) * (puVar8[10] - DAT_800e1158) +
                                     (puVar8[0xc] - DAT_800e1160) * (puVar8[0xc] - DAT_800e1160));
                puVar8[0xa3] = uVar3;
                (**(code **)(&DAT_800e1470 + (*(byte *)(puVar8 + 2) - 0x10) * 4))(puVar8);
              }
              puVar9 = puVar9 + 1;
            } while (puVar9 != DAT_800df93c);
          }
          DAT_800df938 = &DAT_800e1130;
          if ((DAT_800e12da & 0x8000) == 0) {
            FUN_800559b0(&DAT_800e1130);
            FUN_8004dbf8(&DAT_800e1130);
            FUN_8004dcb8(&DAT_800e1130,0x8000);
            FUN_80083a4c(&DAT_800e1130);
            _DAT_8013a400 = 0;
            _DAT_8013a408 = 0;
            iVar4 = FUN_800667d4(&DAT_8013a400,0x1c2,1 << (DAT_800e12d2 & 0x1f),0x8000);
            DAT_800e12dc = DAT_800e12dc | iVar4 << 0x10;
          }
          FUN_8004feac();
          FUN_80074be8();
          if (DAT_800e8928 != (code *)0x0) {
            (*DAT_800e8928)();
          }
        }
        if ((((DAT_800e10ec & 0x4000000) != 0) && (iVar4 = FUN_8004cef8(1), iVar4 == 0)) &&
           (DAT_800e9183 == '\0')) {
          overlay_slot_reader(1,3);
          DAT_800e10ec = DAT_800e10ec & 0xfbffffff;
        }
      }
      else {
        unaff_s6 = uVar3;
        if ((int)(uVar3 * 0x10000) >> 0x10 == 0x10) {
          overlay_slot_reader(1,3);
          DAT_8010b294 = 0;
          unaff_s6 = 0xffff8ad0;
        }
      }
    }
LAB_8009a8a8:
    if ((DAT_800e110c & 0x10000) != 0) {
      FUN_8004a554();
    }
    if ((DAT_800e10ec & 0x100000) == 0) {
      FUN_80062930();
    }
    if ((DAT_80131781 & 1) != 0) {
      FUN_8009af70();
    }
    FUN_80042af4(0);
    puVar9 = &DAT_800e13e8;
    while (puVar9 != DAT_800df93c) {
      puVar8 = (uint *)*puVar9;
      DAT_800df938 = puVar8;
      if (*(char *)(puVar8 + 3) == -1) {
        puVar9 = puVar9 + 1;
      }
      else if ((*puVar8 & 1) == 0) {
        puVar9 = puVar9 + 1;
      }
      else {
        uVar3 = puVar8[0x82];
        if (puVar8 == &DAT_800e1130) {
          _DAT_8013a420 = 0;
          _DAT_8013a424 = 0;
          FUN_800837d0((int)DAT_800e1196,&DAT_8013a420,&DAT_8013a420);
          _DAT_8013a410 = **(int **)(uVar3 + 0x14) + (int)_DAT_8013a420;
          _DAT_8013a414 = *(undefined4 *)(*(int *)(uVar3 + 0x14) + 4);
          puVar6 = &DAT_8013a410;
          _DAT_8013a418 = *(int *)(*(int *)(uVar3 + 0x14) + 8) + (int)_DAT_8013a424;
          bVar1 = 0;
        }
        else {
          bVar1 = *(byte *)((int)puVar8 + 9);
          puVar6 = *(undefined1 **)(uVar3 + 0x14);
        }
        uVar5 = FUN_80069f1c(puVar6,0,(uint)bVar1 << 8,0);
        *(undefined2 *)((int)puVar8 + 0x25e) = uVar5;
        if ((code *)puVar8[0xa8] != (code *)0x0) {
          (*(code *)puVar8[0xa8])(puVar8);
        }
        FUN_80088990(puVar8,puVar8[0x8d],*puVar8,puVar8 + 10);
        if ((DAT_800e110c & 0x10000) != 0) {
          FUN_8004a3e0(puVar8);
        }
        FUN_80033a60(uVar3,(int)((*(ushort *)((int)puVar8 + 0x25e) + 2) * 0x10000) >> 0x10,
                     (int)*(short *)((int)puVar8 + 0x66),(*puVar8 & 0x400) >> 9);
        if ((code *)puVar8[0xa9] != (code *)0x0) {
          (*(code *)puVar8[0xa9])(puVar8);
        }
        *(undefined2 *)(puVar8 + 0xd) = *(undefined2 *)((int)puVar8 + 0x2a);
        *(undefined2 *)((int)puVar8 + 0x36) = *(undefined2 *)((int)puVar8 + 0x2e);
        *(undefined2 *)(puVar8 + 0xe) = *(undefined2 *)((int)puVar8 + 0x32);
        *(undefined2 *)((int)puVar8 + 0x3a) = *(undefined2 *)((int)puVar8 + 0x122);
        *(undefined2 *)(puVar8 + 0xf) = *(undefined2 *)((int)puVar8 + 0x126);
        *(undefined2 *)((int)puVar8 + 0x3e) = *(undefined2 *)((int)puVar8 + 0x12a);
        puVar9 = puVar9 + 1;
      }
    }
    FUN_80050364();
    FUN_80042ad8();
    if (DAT_80131781 != 0) {
      FUN_8009b138();
    }
    FUN_800270a8();
    if (DAT_801317c0 != 0) {
      FUN_80039228();
    }
    FUN_80084510();
    FUN_80033b7c();
    FUN_80074f70();
  } while( true );
}
