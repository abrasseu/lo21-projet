#ifndef SIMULATOR_INTERFACE_H
#define SIMULATOR_INTERFACE_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QString>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>
#include <QVector>
#include <QFileDialog>

#include "../autocell/SimulatorManager.h"
#include "StateInterface.h"
#include "TransitionInterface.h"
#include "../autocell/Simulator.h"
#include "../autocell/State.h"

class StateInterface;

class SimulatorInterface : public QWidget {
	Q_OBJECT		// Macro permettant d'avoir des slots (qui sont uniquement sur Qt)

	protected:
		friend class StateInterface;
		// === Main Layouts
		QHBoxLayout* main_layout;
		QVBoxLayout* state_main_layout;
		QVBoxLayout* controls_layout;
		QVBoxLayout* view_layout;

		// === State Widget
		QVBoxLayout* state_layout_display;
		QVector< QPair<StateInterface*, QPushButton*> >* state_vector = nullptr;
		QPushButton* valid_state;
		QPushButton* add_state;

		// === Control Layouts
		QHBoxLayout* window_controls;
		QHBoxLayout* grid_controls;			// view or grid ?
		QVBoxLayout* simulation_controls;

		// === Automate Controls
		QVBoxLayout* automate_controls;
		QHBoxLayout* state_controls;
		QHBoxLayout* transition_controls;

		// === Choose Automate
		QPushButton* choose_automate;
		QPushButton* change_automate;
        QPushButton* save_automate;

        QPushButton* set_transition_rules;

		// === Window Controls
		QPushButton* quit_bt;
		QPushButton* home_bt;

		// === Grid Controls
		// Dimension Controls
		QVBoxLayout* grid_dim_controls;
		QHBoxLayout* grid_dim_select_layout;
		QLabel* grid_dim_label;
		QSpinBox* grid_dim_spinbox;
		QHBoxLayout* grid_dim_bts_layout;
		QPushButton* grid_dim_set_bt;				// Bouton valider dimension
		QPushButton* grid_dim_reset_bt;			// Bouton invalider dimension

		// Initial State Controls
		QVBoxLayout* initial_state_controls;
		QLabel* initial_state_label;            // Label pour choix grille de départ
		QComboBox* initial_state_selector;      // Liste déroulante avec grilles de départs
		QPushButton* initial_state_setter;

		// === Simulator Controls
		QLabel* simulation_label;				// Label pour toute la partie simulation
		QTimer* sim_timer;
		// Speed Controls
		QHBoxLayout* speed_layout;
		QLabel* speed_label;
		QDoubleSpinBox* speed_selector;			// Spinbox choix des secondes
		// Run Controls
		QHBoxLayout* sim_run_layout;			//Partie gauche de simulation, avec tous les attributs du choix de vitesse + bouton
		QPushButton* sim_start_bt;				// Lancer avec la vitesse
		QPushButton* sim_step_bt;				// Avancer d'un pas
		QPushButton* sim_stop_bt;				// Arrêter la simulation
		QPushButton* sim_reset_bt;				// Reset la simulation

		// Constructor Setters
		void setGridControls(QBoxLayout*);
		void setAutomateControls(QBoxLayout*);
		void setAutomateChoice(QBoxLayout*);
		void setStateControls(QBoxLayout*);
		void setTransitionControls(QBoxLayout*);
		void setDimensionControls(QBoxLayout*);
		void setSimulatorControls(QBoxLayout*);
		void setInitialStateControls(QBoxLayout*);

		void addFirstState(QBoxLayout*);
		void displayExistingStates();

		// Simulation
		const unsigned int automate_dimension;
		SimulatorManager* manager;
		Simulator* simulator = 0;
		bool sim_is_running;
        bool modify_speed_value;
		virtual void blockAfterAutomateChosen() { }
		virtual void blockAfterAutomateChanged() { }

		// Grid
		unsigned int grid_size;			// Taille max de la grille
		unsigned int grid_dimension;
		bool changeCellEnabled;

		// States
		State** initial_states;
		State** possible_state_list;
		unsigned int possible_state_number;
		unsigned int getPossibleStateNumber() const { return possible_state_number; }

		// Methods & Attributes that must be overidded in children
		virtual void redrawGrid(QBoxLayout*) = 0;
		virtual void changeGridCells() = 0;

	public:
		SimulatorInterface(const short unsigned int dim);

	protected slots:
		void home();

		// Simulation Slots
		virtual void start_simulation();
		void speedSelectorChangedValue(double);
		virtual void step_simulation();
		void stop_simulation();
		void reset_simulation();
		void iterate_simulation();

		// Choose Automate
		void chosenAutomate();
		void changedAutomate();

		// State Slots
		void add_new_state();
		void delete_state();

		// Transition Slots
		void choose_transition_rules();
		void choose_transition_rules_finished();

		// Grid Slots
		void set_default_grid();
		void grid_set_dim();
		void grid_reset_dim();

        void saveAutomate();
};

#endif // SIMULATOR_H
